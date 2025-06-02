// This program is a part of NT MudLIB

#include <ansi.h>
#include <combat.h>
#include <net/dns.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
string bar_string = "������������������������";
string blank_string = "������������������������";
string blank_string3 = "������������������������";
string blank_string2 = "������������������������";

mapping oprank = ([
        "����"     : HIW "�������",
        "ʥ�ʾ�"     : HIW "������",
        "������" : HIY "������",
        "���˾�" : HIY "�����  ",
        "������" : HIR "�����  ",
        "������" : HIR "����    ",
        "�����" : HIC "����    ",
        "��������" : HIC "���      ",
        "�ھ�����" : HIG "���      ",
        "��������" : HIG "��        ",
        "��������" : HIM "��        ",
]);

string display_attr(int gift, int value);
string status_color(int current, int max);
string tribar_graph(int val, int eff, int max, string color);
string tribar_graph2(int val, int eff, int max, string color);
string tribar_graph3(int a);
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob;
        mapping my,mci;
        string line , skill_type,*skill_str;
        object weapon;
        int jings, qis, j, i, x, cnt, time;
        int attack_points, dodge_points, parry_points;
        string jbd, msg;
        int can_score = 0;
        int age, month;
        string startroom = "";
        object the_room = 0;
        int len = 0;
		 int lvl, comexp,y;
		comexp = me->query("combat_exp");
     for(y=0;comexp>(y/10)*y*y;y++)
     lvl = y+1;
		time = time();
        seteuid(getuid(me));

        if( !arg ) ob = me;
        else ob = present(arg, environment(me));

        if( !ob ) ob = find_player(arg);
        if( !ob ) ob = find_living(arg);
        if( !ob || !me->visible(ob) ) return notify_fail("��Ҫ�쿴˭��״̬��\n");

        if( wizardp(me) || ob == me )
                can_score = 1;
        else
        if( ob->is_pet() && ob->query("owner") == me->query("id") )
                can_score = 1;
        else
        if( me->query("couple/child_id") == ob->query("id") )
                can_score = 1;
        else
        if( stringp(startroom=ob->query("startroom")) &&
            objectp(the_room = load_object(startroom)) &&
            the_room->query("room_owner_id") == me->query("id") )
                can_score = 1;
        if( !can_score )
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();
        mci = my["combat"];
        if( !mci) mci = ([ ]);

        if( playerp(ob) && (!stringp(my["born"]) || !my["born"]) )
                return notify_fail("��û�г����ţ��쿴ʲô��\n");

        jings = (my["eff_jing"] * 12 / my["max_jing"]) * 2;
        qis = (my["eff_qi"] * 12 / my["max_qi"]) * 2;
        // line = sprintf("                          ��" + MUD_NAME + "�����˵���                      \n\n", ob->query("language"),);
        line = sprintf( BOLD "\n%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
         ob->update_age();

        line += sprintf( YEL "����������������������������������������������\n" NOR );

        if (playerp(ob))
        {
                age = ob->query("age");
                month = ob->query("mud_age");
                if (age >= 60)
                {
                        month -= (age - 60) * 86400 * 4;
                        month = (month - 118 * 86400) / 7200 / 4 + 1;
                } else
                if (age >= 30)
                {
                        month -= (age - 30) * 86400 * 3;
                        month = (month - 28 * 86400) / 7200 / 3 + 1;
                } else
                if (age >= 18)
                {
                        month -= (age - 18) * 86400 * 2;
                        month = (month - 4 * 86400) / 7200 / 2 + 1;
                } else
                {
                        month -= (age - 14) * 86400;
                        month = month / 7200 + 1;
                }

                // not show invalid month
                if (month > 12 || month < 1)
                        month = 1;


                line += sprintf( YEL "" HIY "�����䡿" NOR "%-24s  " YEL "  \n" NOR ,
                        chinese_number(age) + "��" +
                        chinese_number(month) + "����");
        } else
                line += sprintf( YEL "" HIY "�����䡿" NOR "%-24s  " YEL "  " NOR ,
                        chinese_number(ob->query("age"))+"��"+
                        chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200+1)+"����");

        if( objectp(weapon=ob->query_temp("weapon"))){
                skill_type=weapon->query("skill_type");
                attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        } else {
                mapping prepare;
                string *sk;

                prepare = me->query_skill_prepare();
                if( !prepare ) prepare = ([]);
                sk = keys(prepare);

                if( sizeof(sk) == 0 ) skill_type = "unarmed";
                else skill_type = sk[0];
                attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
                if( sizeof(prepare) == 2 ) {
                        mixed temp;
                        temp = COMBAT_D->skill_power(ob, sk[1], SKILL_USAGE_ATTACK);

                        if( attack_points < temp)
                                attack_points = temp;
                }
        }
        line += sprintf( YEL "" HIY "��������" MAG "%-28.28s" NOR+YEL "\n" NOR ,
                CHINESE_D->chinese_date(ob->query("birthday")));

        parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
		
		line += sprintf( YEL "" HIY "�����塿" NOR "%-26.8s" YEL "  \n" NOR ,
                    ob->query("race"));		
					
		
					

        line += sprintf( YEL "" HIY "���Ա�" NOR "%-26.8s" YEL "  \n" NOR ,
                    ob->query("gender"));			


        line += sprintf( YEL "" HIY "���Ը�" NOR "%-28.28s" YEL "\n" NOR ,
                ob->query("character")?ob->query("character"):"��δȷ��");


        line+=sprintf(YEL""HIW"�����ɡ�"NOR"%-18.18s\n",stringp(ob->query("bunch/bunch_name"))?ob->query("bunch/bunch_name"):"������ʿ");

        if( stringp(ob->query("degree")) )
        {
#ifndef LONELY_IMPROVED
                len=color_len(ob->query("degree"));
#endif
                line+=sprintf(YEL""HIW"��ְ��"NOR"%"+sprintf("%d",18+len)+"-s",ob->query("degree"));
        }
        else
        if( stringp(ob->query("bunch/title")) )
                line+=sprintf(YEL""HIW"��ְ��"NOR"%"+sprintf("%d\n",18+color_len(ob->query("bunch/title")))+"-s",ob->query("bunch/title"));
        else
                line += sprintf( YEL "" HIW "��ְ��" NOR "��                \n" );
        line+=sprintf(YEL""HIM"��ְҵ��"NOR"%-18s\n"YEL""NOR,ob->query("is_vendor")?"����":"��");
    if (mapp(my["family"]))
			line += sprintf(HIG"�����ɡ���%s��"NOR"\n",my["family"]["family_name"]);
    else
			line += HIG"�����ɡ�������"NOR"\n";
      
								
	if (mapp(my["family"]))
	{
		if (my["family"]["master_name"])
			line += sprintf(HIG"��ʦ�С���%s��"NOR"\n",my["family"]["master_name"]);
		else
			line += HIG"��ʦ�С�������"NOR"\n";
	} else
		line += HIG"\n��ʦ�С�������"NOR"\n";


        line += sprintf( YEL "�ǩ���������������������������������������������\n" NOR );

        line += sprintf( YEL "" HIY "����Ϊ���򣩡�" HIW "%-10d\n" HIY "��Ǳ�ܣ��򣩡�" NOR "%s%-10d" NOR YEL "\n" NOR ,my["combat_exp"]/10000,(int)ob->query("potential")/10000>=(int)ob->query_potential_limit()?HIM:HIW,(int)ob->query("potential")/10000 - (int)ob->query("learned_points")/10000 );

        line += sprintf( HIY "��%s��" HIW "%-10d\n" HIY "����᡿" HIW "%s%-10d" NOR YEL "\n" NOR ,(ob->query("shen")>=0)?"����":"а��",ob->query("shen")?ob->query("shen"):0,my["combat_exp"] < 100000 ? HIR :
                        my["experience"] < ob->query_experience_limit() ? HIW : HIM,
                        my["experience"] - my["learned_experience"] );
        //line+=sprintf(YEL""HIC"��Ԫ��"NOR"%-18.8s\n",ob->query("yuanshen_level")?ob->query("yuanshen_level")+" ��":"��");
        line += sprintf( YEL "" HIY "����ݡ�" NOR HIW "%-10d" NOR YEL "\n" NOR  ,my["magic_points"] - my["magic_learned"] );

        line += sprintf( YEL "" HIY "��������" HIW "%-30d\n" HIY "��������" NOR HIW "%-10d" NOR YEL "\n" NOR , ob->query("weiwang") ,ob->query("score") );
		
        /*
        if( mapp(my["couple"]))
        {
                line += sprintf( YEL "" HIW "��������" NOR "%-18.8s" , "���" + chinese_number(my["couple"]["married"]) + "��");
                line+=sprintf(YEL""HIY"��������"NORHIW"%-10d"NORHIY"��������"NORHIW"%-10d"NORYEL"\n"NOR,query("score", ob)?query("score", ob):0,query("total_hatred", ob)?query("total_hatred", ob):0);
                if( my["couple"]["have_couple"])
                {
                        line += sprintf( YEL "" HIW "��%s��" NOR "%-18.8s" YEL "����������������������������������������\n" NOR , my["couple"]["couple_gender"],my["couple"]["couple_name"] + "(" + my["couple"]["couple_id"]  + ")");
                } else
                {
                        line += sprintf( YEL "" HIW "�����¡�" NOR "%-18.8s" YEL "����������������������������������������\n" NOR , "û��");
                }
                line += sprintf( YEL "" HIW "����Ů��" NOR "%-56s" NOR YEL "\n", mapp(my["couple"]["child"]) ? my["couple"]["child"]["name"] : "û��");
        }
        */

        if( mapp(my["couple"]))
        {
			//	line+=sprintf(YEL""HIR"��������"NOR"%-10s        \n",ob->query("jungong")?ob->query("jungong")+" ��":"0 ��");
                line += sprintf( YEL "" HIR "����ȯ��" NOR HIW "%-30d\n" NOR HIR "��������"NOR HIW "%-10d" NOR YEL "\n" NOR ,ob->query("jifeng")?ob->query("jifeng"):0,ob->query("total_hatred")?ob->query("total_hatred"):0 );
             //   line += sprintf( YEL "" HIW "��������" NOR "%-18.8s\n" , my["couple"]["couple_name"] ? "���" : "����");
			//	if( my["couple"]["couple_name"])
               // {
               //         line += sprintf( YEL "" HIW "��%s��" NOR "%-18s" YEL "\n" NOR , "����",my["couple"]["couple_name"] + "(" + my["couple"]["couple_id"]  + ")");
              ///  } else
              //  {
             //           line += sprintf( YEL "" HIW "�����¡�" NOR "%-18.8s" YEL "\n" NOR , "û��");
              //  }
             
					if (! ob->query("couple/name"))
			{
				if (ob->query("gender") == "Ů��")
					line += HIW "�����¡�  ����δ���䡣\n" NOR;
				else
					line += HIW "�����¡�  ����δȢ�ޡ�\n" NOR;
			} else
				line += HIW "  ��İ�����" + ob->query("couple/name") + "(" +
					ob->query("couple/id") + ")��\n" NOR;
			 //line += sprintf( YEL "" HIW "����Ů��" NOR "%-56s" NOR YEL "\n", my["couple"]["child_name"] ? my["couple"]["child_name"] : "û��");
        }
        else
        {
			//	line+=sprintf(YEL""HIR"��������"NOR"%-10s        \n",ob->query("jungong")?ob->query("jungong")+" ��":"0 ��");
                line += sprintf( YEL "" HIR "����ȯ��" NOR HIW "%-30d\n" NOR HIR "��������"NOR HIW "%-10d" NOR YEL "\n" NOR ,ob->query("jifeng")?ob->query("jifeng"):0,ob->query("total_hatred")?ob->query("total_hatred"):0 );
            //    line += sprintf( YEL "" HIW "��������" NOR "����              \n" );
			//	line += sprintf( YEL "" HIW "�����¡�" NOR "û��              " YEL "\n" NOR );
             



				if (! ob->query("couple/name"))
			{
				if (ob->query("gender") == "Ů��")
					line += HIW "�����¡�  ����δ���䡣\n" NOR;
				else
					line += HIW "�����¡�  ����δȢ�ޡ�\n" NOR;
			} else
				line += HIW "  ��İ�����" + ob->query("couple/name") + "(" +
					ob->query("couple/id") + ")��\n" NOR;
					// line += sprintf( YEL "" HIW "����Ů��" NOR "%-56s" NOR YEL "\n", "û��" );
        }
		/*
        if( !ob->query("private_room") )
                line += sprintf( YEL "" HIW "��סլ��" NOR "%-18.8s\n" , "���˽�ͷ");
        else
                line+=sprintf(YEL""HIW"��סլ��"NOR"%-18.8s\n",ob->query("private_room/name"));*/
        if( my["gender"] == "����")
                line += sprintf( YEL "" HIW "�����ԡ�" NOR "%-56s" NOR YEL "\n","���Ǹ�̫�ࡣ" );
        else if( !ob->query("sex/times") )
        {
                if( my["gender"] == "Ů��")
                        line += sprintf( YEL "" HIW "�����ԡ�" NOR "%-56s" NOR YEL "\n","�㻹�Ǵ�Ů��" );
                else
                        line += sprintf( YEL "" HIW "�����ԡ�" NOR "%-56s" NOR YEL "\n","�㻹��ͯ�С�" );
        } else
        {
                string *ks;
                ks=keys(ob->query("sex"));
                ks -= ({ "times", "first", "" });
                if( sizeof(ks) >= 5)
                        line += sprintf( YEL "" HIW "�����ԡ�" NOR "%-56s" NOR YEL "\n",
                                         "����������������˷�������ϵ�����Լ���������˭��");
                else
                {
                        msg = "��������" + implode(ks,"��") + "��������ϵ��";
#ifndef LONELY_IMPROVED
                        len = color_len(msg);
#endif
                        line += sprintf( YEL "" HIW "�����ԡ�" NOR "%" + sprintf("%d", (56 + len)) + "-s" NOR YEL "\n",
                                         "��������" + implode(ks,"��") + "��������ϵ��");
                }
        }

        line += sprintf( YEL "" HIW "�����" NOR "%-56s" NOR YEL "\n", mapp(ob->query("can_whistle")) ? "ӵ��" : "û��");
		
        //line+=sprintf(HIG"�����ڴ�����"NOR"%-10s",ob->query("jiebiao")?ob->query("jiebiao")+" ��":"������")+ """\n";
		
		
      //  line+=sprintf(HIG"�����Ŵ�����"NOR"%-10s",ob->query("fuben/wuguan/mun")?ob->query("fuben/wuguan/mun")+" ��":"������")+ """\n";
		
		line += HIC"�����ѵ����["+me->query("fuben/wuguan/mun")+"/2]:\n"NOR;
		line += HIC"�����������["+me->query("fuben/jinbing/mun")+"/2]:\n"NOR;	
		line += HIC"����̬������["+me->query("fuben/jinbing1/mun")+"/2]:\n"NOR;	

		line += HIC"��������Ԫ��["+me->query("fuben/poyuan/mun")+"/2]:\n"NOR;		
		line += HIC"��ʮ�����꡿["+me->query("fuben/huangling/mun")+"/2]:\n"NOR;	
		line += HIC"����ƽ���ܡ�["+me->query("fuben/dangkou/mun")+"/2]:\n"NOR;	
		line += HIC"������ȡ�["+me->query("kuangdao/menpiao")+"/2]:\n"NOR;	
		line += HIC"���ű�/���ݱ��ҡ�["+me->query("fubentd")+"/2]:\n"NOR;		

		
		
		line += HIY "����Ա�ȼ�����"+ob->query("vipdj")+ "����"NOR"\n";

        line += HIY"����Աʱ�䡿��"+CHINESE_D->chinese_time(me->query("zjvip/times"))+ "��"NOR"\n";
		
        line+= sprintf(HIG"����ʯ��"NOR"%-10s",ob->query("yuanbao")?ob->query("yuanbao")+" ����ʯ":"û��")+ """\n";

		line += HIY "��ʦ�Ź�������"+ob->query("gongxian")+ "�㡣"NOR"\n";
		
		line += sprintf(HIC"���书���ޡ���" NOR + " [%2d]""\n", lvl);
		
		line += HIY "  ����ת��:"+ob->query("zhuanshi",1)+"�Ρ�"NOR"\n";
		
		if((int)ob->query("tingyvge")> 0)
		line += HIY "�������ʱ�䡿��"+CHINESE_D->short_time(ob->query("tingyvge"))+ "��"NOR"\n";
	    if((int)ob->query("lenque")> 0)
		line += HIY "���������ȴ����"+CHINESE_D->short_time(ob->query("lenque"))+ "��"NOR"\n";
		
		
        if( !ob->query("balance") )
                line += sprintf( YEL "" HIY "��Ǯׯ��" HIY "û�л���                                                " NOR+YEL "\n" NOR );
        else
        {
                line += sprintf ( YEL ""  HIY "��Ǯׯ��" NOR );
                line += sprintf (HIY"%-56.56s"NOR,
                MONEY_D->money_str(ob->query("balance")));
                line += sprintf ( NOR+YEL "\n" NOR );
        }

        line += sprintf( YEL "�ǩ���������������������������������������������\n" NOR );

        line += sprintf( HIW "��ս����������" NOR "%12d" YEL "\n" NOR ,ob->query_temp("apply/armor"));

        line += sprintf( HIW "��ս����������" NOR "%12d" YEL "\n" NOR ,dodge_points /10000 + (weapon? parry_points: (parry_points /100)/10000)/10000 + 1);

        line += sprintf( HIW "��ս���˺�����" NOR "%12d" YEL "\n" NOR ,ob->query_temp("apply/damage" )+ob->query_temp("apply/unarmed_damage"));

        line += sprintf( HIW "��ս����������" NOR "%12d" YEL "\n" NOR ,attack_points /10000 + 1);
		
        line += sprintf( YEL "�ǩ���������������������������������������������\n" NOR );

        if( my["max_jing"] >= my["eff_jing"])
                line += sprintf( YEL "" HIC"������"NOR"��%-24s   \n", tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])) + tribar_graph3(jings));
        else
                line += sprintf( YEL "" HIC"������"NOR"��%-24s   \n" , tribar_graph2(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]))+ tribar_graph3(jings));

        if( my["max_jingli"] > 0 )
                line += sprintf( HIC "��������"NOR"��%-24s"+ NOR+YEL+"\n"NOR, tribar_graph(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"])));
        else
                line += sprintf( HIC "��������"NOR "��" HIG "%-24s"+ NOR+YEL+"\n"NOR, blank_string );

        if( my["max_qi"] >= my["eff_qi"])
                line += sprintf( YEL "" HIC"����Ѫ��"NOR"��%-24s   \n", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));
        else
                line += sprintf( YEL "" HIC"����Ѫ��"NOR"��%-24s   \n", tribar_graph2(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));

        if( my["max_neili"] > 0 )
                line += sprintf( HIC "��������"NOR"��%-24s"+ NOR+YEL+"\n"NOR, tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
        else
                line += sprintf( HIC "��������"NOR "��" HIG "%-24s"+ NOR+YEL+"\n"NOR, blank_string );

        if( ob->max_food_capacity() > 0 )
                line += sprintf( YEL "" HIC"��ʳ�"NOR"��%-24s   \n", tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL));
        else
                line += sprintf( YEL "" HIC"��ʳ�"NOR"��"YEL   "%-24s"+ NOR+YEL+"\n"NOR, blank_string );

        if( ob->max_water_capacity() > 0 )
                line += sprintf( HIC "����ˮ��"NOR"��%-24s"+ NOR+YEL+"\n"NOR , tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN));
        else
                line += sprintf( HIC "����ˮ��"NOR CYN"��%-24s"+ NOR+YEL+"\n"NOR, blank_string );

        line += sprintf( YEL "�ǩ���������������������������������������������\n" NOR );

		if (my["born_family"] && my["born_family"] != "û��")
		{
			line += HIW "���Ը񡿣���" + my["character"]+"��";
		}
		else if (stringp(my["born"]) && my["born"])
		{
			line += HIW "���Ը񡿣���" + my["character"]+"��\n";
		}
		else
			line += HIW "  ����δ����";

		skill_str=keys(me->query("special_skill"));
		line +=HIG"���츳����"NOR;
		for(i=0; i<sizeof(skill_str); i++)
		{
			line +=HIG"��"+SPECIAL_D(skill_str[i])->name()+HIG"��";
		}
        line += sprintf( YEL "\n" NOR );
        line += sprintf( HIY "����������" HIW "%2d |%4d  " HIY "�����ԡ���" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
                ob->query("str"),
                ob->query_str(),
                ob->query("int"),
                ob->query_int());


        line += sprintf( HIY "�����ǡ���" HIW "%2d |%4d  " HIY "��������" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
                ob->query("con"),
                ob->query_con(),
                ob->query("dex"),
                ob->query_dex());
				
		line += sprintf( HIY "����ò����" HIW "%2d |%4d  " HIY "����Ե����" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
                ob->query("per"),
                ob->query_per(),
                ob->query("kar"),
                ob->query_kar());
			
        line += sprintf( YEL "�ǩ���������������������������������������������\n" NOR );

        line += sprintf( YEL "" HIC "��ȭ�š�" NOR "%s" HIC "��������" NOR "%s" NOR YEL "\n" NOR,ob->query("opinion/unarmed")? oprank[ob->query("opinion/unarmed")]:CYN "������    " NOR,ob->query("opinion/weapon")? oprank[ob->query("opinion/weapon")]:CYN "������    " NOR);

        line += sprintf( YEL "" HIC "���ڹ���" NOR "%s" HIC "���Ṧ��" NOR "%s" NOR YEL "\n" NOR,ob->query("opinion/force")? oprank[ob->query("opinion/force")]:CYN "������    " NOR,ob->query("opinion/dodge")? oprank[ob->query("opinion/dodge")]:CYN "������    " NOR);

		line += sprintf( YEL "�ǩ���������������������������������������������\n" NOR );
        line += sprintf( YEL "                                                                \n" NOR );
        line += sprintf( YEL "" NOR HIY "   ��ѧ��ʦ�� %s" NOR HIY "    �ζ������� %s\n" NOR HIY "   ԪӤ������ %s" NOR HIY "    �������أ� %s " NOR YEL "\n" NOR,
                ultrap(ob)?"��":HIC"��",ob->query("breakup")?"��":HIC"��",ob->query("animaout")?"��":HIC"��",ob->query("death")?"��":HIC"��");

        line += sprintf( YEL "�ǩ���������������������������������������������\n" NOR );

        line += sprintf( YEL "" HIB "��ɱ��������" NOR HIR"%dλ"NOR,
                (int)mci["MKS"] + (int)mci["PKS"]);
        line += sprintf( YEL "" HIB "��ɱ����ҡ�" NOR HIR"%dλ\n"NOR,
                (int)mci["PKS"]);
        line += sprintf( YEL "" HIB "������ɱ����" NOR HIR"%dλ"NOR,
                (int)mci["WPK"]);

        line += sprintf( YEL "" HIB "��������ҡ�" NOR HIR"%dλ\n"NOR,
                (int)mci["DPS"]);
        line += sprintf( YEL "" HIB "��������ʿ��" NOR HIR"%dλ"NOR,
                (int)mci["DPS_GOOD"]);
        line += sprintf( YEL "" HIB "��а����ʿ��" NOR HIR"%dλ"NOR,
                (int)mci["DPS_BAD"]);
        line += YEL "\n" NOR;

        line += sprintf( YEL "�ǩ���������������������������������������������\n" NOR );

	//	line += HIG "   ��Ŀǰ�ġ��ȯ����:( "+HIM+my["suit_point"]+HIG+" )�� "NOR"\n";

        msg = "";
        if( (int)mci["dietimes"])
                msg = sprintf(HIW "   �㵽ĿǰΪֹ�ܹ����ڰ��޳�����"
                                "����%s�Ρ�" NOR,
                                chinese_number(mci["dietimes"]))+ "\n";
        if( stringp(mci["last_die"]))
                line += sprintf(HIR "   �����һ����%s��" NOR,mci["last_die"])+ "\n";
        if( msg != "")
        {
#ifndef LONELY_IMPROVED
                len = color_len(msg);
#endif
                line += sprintf( "%" + sprintf("%d",(64 + len)) + "-s" NOR, msg )+ "\n";
        }
        line += YEL "���������������������������˵���������������������\n" NOR;

        line += sprintf( HIW "   ��ʵ�����ʱ�䣺" + ctime( time ) + "��\n"NOR);
        line += sprintf( HIW "   ����Ǳ�ܵ�ʱ�䣺"+ CHINESE_D->chinese_time(me->query("qnvip/times"))+ "��"NOR"\n");
				line = replace_string(line,"\n",ZJBR)+"\n";
				write(ZJOBLONG+line+"\n");
        return 1;
}


string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%6s" NOR, chinese_number(value) );
        else if( value < gift ) return sprintf( CYN "%6s" NOR, chinese_number(value) );
        else return sprintf("%6s", chinese_number(value));
}

string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;

        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return HIB;
}

string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph2(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string2[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph3(int a)
{
        return BLU + blank_string3[0..(23-a)] + NOR;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}
