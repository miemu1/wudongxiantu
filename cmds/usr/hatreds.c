// This program is a part of NT MudLIB

#include <ansi.h>
#include <combat.h>
#include <net/dns.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
string bar_string = "■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□";
string blank_string3 = "□□□□□□□□□□□□";
string blank_string2 = "　　　　　　　　　　　　";

mapping oprank = ([
        "帝尊境"     : HIW "★★★★★★",
        "圣皇境"     : HIW "★★★★★",
        "真王境" : HIY "★★★★☆",
        "天人境" : HIY "★★★★  ",
        "超凡境" : HIR "★★★☆  ",
        "涅槃境" : HIR "★★★    ",
        "罡劲高手" : HIC "★★☆    ",
        "化劲高手" : HIC "★★      ",
        "内劲高手" : HIG "★☆      ",
        "暗劲高手" : HIG "★        ",
        "明劲高手" : HIM "☆        ",
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
        if( !ob || !me->visible(ob) ) return notify_fail("你要察看谁的状态？\n");

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
                return notify_fail("只有巫师能察看别人的状态。\n");

        my = ob->query_entire_dbase();
        mci = my["combat"];
        if( !mci) mci = ([ ]);

        if( playerp(ob) && (!stringp(my["born"]) || !my["born"]) )
                return notify_fail("还没有出生呐，察看什么？\n");

        jings = (my["eff_jing"] * 12 / my["max_jing"]) * 2;
        qis = (my["eff_qi"] * 12 / my["max_qi"]) * 2;
        // line = sprintf("                          【" + MUD_NAME + "】个人档案                      \n\n", ob->query("language"),);
        line = sprintf( BOLD "\n%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
         ob->update_age();

        line += sprintf( YEL "━━━━━━━━━━━━━━━━━━━━━━━\n" NOR );

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


                line += sprintf( YEL "" HIY "【年龄】" NOR "%-24s  " YEL "  \n" NOR ,
                        chinese_number(age) + "岁" +
                        chinese_number(month) + "个月");
        } else
                line += sprintf( YEL "" HIY "【年龄】" NOR "%-24s  " YEL "  " NOR ,
                        chinese_number(ob->query("age"))+"岁"+
                        chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200+1)+"个月");

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
        line += sprintf( YEL "" HIY "【生辰】" MAG "%-28.28s" NOR+YEL "\n" NOR ,
                CHINESE_D->chinese_date(ob->query("birthday")));

        parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
		
		line += sprintf( YEL "" HIY "【种族】" NOR "%-26.8s" YEL "  \n" NOR ,
                    ob->query("race"));		
					
		
					

        line += sprintf( YEL "" HIY "【性别】" NOR "%-26.8s" YEL "  \n" NOR ,
                    ob->query("gender"));			


        line += sprintf( YEL "" HIY "【性格】" NOR "%-28.28s" YEL "\n" NOR ,
                ob->query("character")?ob->query("character"):"还未确定");


        line+=sprintf(YEL""HIW"【帮派】"NOR"%-18.18s\n",stringp(ob->query("bunch/bunch_name"))?ob->query("bunch/bunch_name"):"自由人士");

        if( stringp(ob->query("degree")) )
        {
#ifndef LONELY_IMPROVED
                len=color_len(ob->query("degree"));
#endif
                line+=sprintf(YEL""HIW"【职务】"NOR"%"+sprintf("%d",18+len)+"-s",ob->query("degree"));
        }
        else
        if( stringp(ob->query("bunch/title")) )
                line+=sprintf(YEL""HIW"【职务】"NOR"%"+sprintf("%d\n",18+color_len(ob->query("bunch/title")))+"-s",ob->query("bunch/title"));
        else
                line += sprintf( YEL "" HIW "【职务】" NOR "无                \n" );
        line+=sprintf(YEL""HIM"【职业】"NOR"%-18s\n"YEL""NOR,ob->query("is_vendor")?"商人":"无");
    if (mapp(my["family"]))
			line += sprintf(HIG"【门派】：%s。"NOR"\n",my["family"]["family_name"]);
    else
			line += HIG"【门派】：尚无"NOR"\n";
      
								
	if (mapp(my["family"]))
	{
		if (my["family"]["master_name"])
			line += sprintf(HIG"【师承】：%s。"NOR"\n",my["family"]["master_name"]);
		else
			line += HIG"【师承】：尚无"NOR"\n";
	} else
		line += HIG"\n【师承】：尚无"NOR"\n";


        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );

        line += sprintf( YEL "" HIY "【修为（万）】" HIW "%-10d\n" HIY "【潜能（万）】" NOR "%s%-10d" NOR YEL "\n" NOR ,my["combat_exp"]/10000,(int)ob->query("potential")/10000>=(int)ob->query_potential_limit()?HIM:HIW,(int)ob->query("potential")/10000 - (int)ob->query("learned_points")/10000 );

        line += sprintf( HIY "【%s】" HIW "%-10d\n" HIY "【体会】" HIW "%s%-10d" NOR YEL "\n" NOR ,(ob->query("shen")>=0)?"正气":"邪气",ob->query("shen")?ob->query("shen"):0,my["combat_exp"] < 100000 ? HIR :
                        my["experience"] < ob->query_experience_limit() ? HIW : HIM,
                        my["experience"] - my["learned_experience"] );
        //line+=sprintf(YEL""HIC"【元神】"NOR"%-18.8s\n",ob->query("yuanshen_level")?ob->query("yuanshen_level")+" 级":"无");
        line += sprintf( YEL "" HIY "【灵惠】" NOR HIW "%-10d" NOR YEL "\n" NOR  ,my["magic_points"] - my["magic_learned"] );

        line += sprintf( YEL "" HIY "【威望】" HIW "%-30d\n" HIY "【阅历】" NOR HIW "%-10d" NOR YEL "\n" NOR , ob->query("weiwang") ,ob->query("score") );
		
        /*
        if( mapp(my["couple"]))
        {
                line += sprintf( YEL "" HIW "【婚姻】" NOR "%-18.8s" , "结婚" + chinese_number(my["couple"]["married"]) + "次");
                line+=sprintf(YEL""HIY"【阅历】"NORHIW"%-10d"NORHIY"【戾气】"NORHIW"%-10d"NORYEL"\n"NOR,query("score", ob)?query("score", ob):0,query("total_hatred", ob)?query("total_hatred", ob):0);
                if( my["couple"]["have_couple"])
                {
                        line += sprintf( YEL "" HIW "【%s】" NOR "%-18.8s" YEL "┗━━━━━━━━━━━━━━━━━━┫\n" NOR , my["couple"]["couple_gender"],my["couple"]["couple_name"] + "(" + my["couple"]["couple_id"]  + ")");
                } else
                {
                        line += sprintf( YEL "" HIW "【伴侣】" NOR "%-18.8s" YEL "┗━━━━━━━━━━━━━━━━━━┫\n" NOR , "没有");
                }
                line += sprintf( YEL "" HIW "【子女】" NOR "%-56s" NOR YEL "\n", mapp(my["couple"]["child"]) ? my["couple"]["child"]["name"] : "没有");
        }
        */

        if( mapp(my["couple"]))
        {
			//	line+=sprintf(YEL""HIR"【军功】"NOR"%-10s        \n",ob->query("jungong")?ob->query("jungong")+" 策":"0 策");
                line += sprintf( YEL "" HIR "【点券】" NOR HIW "%-30d\n" NOR HIR "【戾气】"NOR HIW "%-10d" NOR YEL "\n" NOR ,ob->query("jifeng")?ob->query("jifeng"):0,ob->query("total_hatred")?ob->query("total_hatred"):0 );
             //   line += sprintf( YEL "" HIW "【婚姻】" NOR "%-18.8s\n" , my["couple"]["couple_name"] ? "结婚" : "离异");
			//	if( my["couple"]["couple_name"])
               // {
               //         line += sprintf( YEL "" HIW "【%s】" NOR "%-18s" YEL "\n" NOR , "伴侣",my["couple"]["couple_name"] + "(" + my["couple"]["couple_id"]  + ")");
              ///  } else
              //  {
             //           line += sprintf( YEL "" HIW "【伴侣】" NOR "%-18.8s" YEL "\n" NOR , "没有");
              //  }
             
					if (! ob->query("couple/name"))
			{
				if (ob->query("gender") == "女性")
					line += HIW "【伴侣】  你尚未婚配。\n" NOR;
				else
					line += HIW "【伴侣】  你尚未娶妻。\n" NOR;
			} else
				line += HIW "  你的伴侣是" + ob->query("couple/name") + "(" +
					ob->query("couple/id") + ")。\n" NOR;
			 //line += sprintf( YEL "" HIW "【子女】" NOR "%-56s" NOR YEL "\n", my["couple"]["child_name"] ? my["couple"]["child_name"] : "没有");
        }
        else
        {
			//	line+=sprintf(YEL""HIR"【军功】"NOR"%-10s        \n",ob->query("jungong")?ob->query("jungong")+" 策":"0 策");
                line += sprintf( YEL "" HIR "【点券】" NOR HIW "%-30d\n" NOR HIR "【戾气】"NOR HIW "%-10d" NOR YEL "\n" NOR ,ob->query("jifeng")?ob->query("jifeng"):0,ob->query("total_hatred")?ob->query("total_hatred"):0 );
            //    line += sprintf( YEL "" HIW "【婚姻】" NOR "单身              \n" );
			//	line += sprintf( YEL "" HIW "【伴侣】" NOR "没有              " YEL "\n" NOR );
             



				if (! ob->query("couple/name"))
			{
				if (ob->query("gender") == "女性")
					line += HIW "【伴侣】  你尚未婚配。\n" NOR;
				else
					line += HIW "【伴侣】  你尚未娶妻。\n" NOR;
			} else
				line += HIW "  你的伴侣是" + ob->query("couple/name") + "(" +
					ob->query("couple/id") + ")。\n" NOR;
					// line += sprintf( YEL "" HIW "【子女】" NOR "%-56s" NOR YEL "\n", "没有" );
        }
		/*
        if( !ob->query("private_room") )
                line += sprintf( YEL "" HIW "【住宅】" NOR "%-18.8s\n" , "流浪街头");
        else
                line+=sprintf(YEL""HIW"【住宅】"NOR"%-18.8s\n",ob->query("private_room/name"));*/
        if( my["gender"] == "无性")
                line += sprintf( YEL "" HIW "【两性】" NOR "%-56s" NOR YEL "\n","你是个太监。" );
        else if( !ob->query("sex/times") )
        {
                if( my["gender"] == "女性")
                        line += sprintf( YEL "" HIW "【两性】" NOR "%-56s" NOR YEL "\n","你还是处女。" );
                else
                        line += sprintf( YEL "" HIW "【两性】" NOR "%-56s" NOR YEL "\n","你还是童男。" );
        } else
        {
                string *ks;
                ks=keys(ob->query("sex"));
                ks -= ({ "times", "first", "" });
                if( sizeof(ks) >= 5)
                        line += sprintf( YEL "" HIW "【两性】" NOR "%-56s" NOR YEL "\n",
                                         "你曾经和数不清的人发生过关系，连自己都忘了有谁。");
                else
                {
                        msg = "你曾经和" + implode(ks,"、") + "发生过关系。";
#ifndef LONELY_IMPROVED
                        len = color_len(msg);
#endif
                        line += sprintf( YEL "" HIW "【两性】" NOR "%" + sprintf("%d", (56 + len)) + "-s" NOR YEL "\n",
                                         "你曾经和" + implode(ks,"、") + "发生过关系。");
                }
        }

        line += sprintf( YEL "" HIW "【坐骑】" NOR "%-56s" NOR YEL "\n", mapp(ob->query("can_whistle")) ? "拥有" : "没有");
		
        //line+=sprintf(HIG"【劫镖次数】"NOR"%-10s",ob->query("jiebiao")?ob->query("jiebiao")+" 次":"用完了")+ """\n";
		
		
      //  line+=sprintf(HIG"【衙门次数】"NOR"%-10s",ob->query("fuben/wuguan/mun")?ob->query("fuben/wuguan/mun")+" 次":"用完了")+ """\n";
		
		line += HIC"【武馆训练】["+me->query("fuben/wuguan/mun")+"/2]:\n"NOR;
		line += HIC"【伏击金兵】["+me->query("fuben/jinbing/mun")+"/2]:\n"NOR;	
		line += HIC"【拟态修炼】["+me->query("fuben/jinbing1/mun")+"/2]:\n"NOR;	

		line += HIC"【单骑破元】["+me->query("fuben/poyuan/mun")+"/2]:\n"NOR;		
		line += HIC"【十三皇陵】["+me->query("fuben/huangling/mun")+"/2]:\n"NOR;	
		line += HIC"【荡平倭寇】["+me->query("fuben/dangkou/mun")+"/2]:\n"NOR;	
		line += HIC"【狂盗谷】["+me->query("kuangdao/menpiao")+"/2]:\n"NOR;	
		line += HIC"【团本/扬州暴乱】["+me->query("fubentd")+"/2]:\n"NOR;		

		
		
		line += HIY "【会员等级】："+ob->query("vipdj")+ "级。"NOR"\n";

        line += HIY"【会员时间】："+CHINESE_D->chinese_time(me->query("zjvip/times"))+ "。"NOR"\n";
		
        line+= sprintf(HIG"【灵石】"NOR"%-10s",ob->query("yuanbao")?ob->query("yuanbao")+" 个灵石":"没有")+ """\n";

		line += HIY "【师门功绩】："+ob->query("gongxian")+ "点。"NOR"\n";
		
		line += sprintf(HIC"【武功上限】：" NOR + " [%2d]""\n", lvl);
		
		line += HIY "  你已转世:"+ob->query("zhuanshi",1)+"次。"NOR"\n";
		
		if((int)ob->query("tingyvge")> 0)
		line += HIY "【听雨阁时间】："+CHINESE_D->short_time(ob->query("tingyvge"))+ "。"NOR"\n";
	    if((int)ob->query("lenque")> 0)
		line += HIY "【听雨阁冷却】："+CHINESE_D->short_time(ob->query("lenque"))+ "。"NOR"\n";
		
		
        if( !ob->query("balance") )
                line += sprintf( YEL "" HIY "【钱庄】" HIY "没有积蓄                                                " NOR+YEL "\n" NOR );
        else
        {
                line += sprintf ( YEL ""  HIY "【钱庄】" NOR );
                line += sprintf (HIY"%-56.56s"NOR,
                MONEY_D->money_str(ob->query("balance")));
                line += sprintf ( NOR+YEL "\n" NOR );
        }

        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );

        line += sprintf( HIW "【战斗保护力】" NOR "%12d" YEL "\n" NOR ,ob->query_temp("apply/armor"));

        line += sprintf( HIW "【战斗防御力】" NOR "%12d" YEL "\n" NOR ,dodge_points /10000 + (weapon? parry_points: (parry_points /100)/10000)/10000 + 1);

        line += sprintf( HIW "【战斗伤害力】" NOR "%12d" YEL "\n" NOR ,ob->query_temp("apply/damage" )+ob->query_temp("apply/unarmed_damage"));

        line += sprintf( HIW "【战斗攻击力】" NOR "%12d" YEL "\n" NOR ,attack_points /10000 + 1);
		
        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );

        if( my["max_jing"] >= my["eff_jing"])
                line += sprintf( YEL "" HIC"【精神】"NOR"：%-24s   \n", tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])) + tribar_graph3(jings));
        else
                line += sprintf( YEL "" HIC"【精神】"NOR"：%-24s   \n" , tribar_graph2(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]))+ tribar_graph3(jings));

        if( my["max_jingli"] > 0 )
                line += sprintf( HIC "【精力】"NOR"：%-24s"+ NOR+YEL+"\n"NOR, tribar_graph(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"])));
        else
                line += sprintf( HIC "【精力】"NOR "：" HIG "%-24s"+ NOR+YEL+"\n"NOR, blank_string );

        if( my["max_qi"] >= my["eff_qi"])
                line += sprintf( YEL "" HIC"【气血】"NOR"：%-24s   \n", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));
        else
                line += sprintf( YEL "" HIC"【气血】"NOR"：%-24s   \n", tribar_graph2(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));

        if( my["max_neili"] > 0 )
                line += sprintf( HIC "【内力】"NOR"：%-24s"+ NOR+YEL+"\n"NOR, tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
        else
                line += sprintf( HIC "【内力】"NOR "：" HIG "%-24s"+ NOR+YEL+"\n"NOR, blank_string );

        if( ob->max_food_capacity() > 0 )
                line += sprintf( YEL "" HIC"【食物】"NOR"：%-24s   \n", tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL));
        else
                line += sprintf( YEL "" HIC"【食物】"NOR"："YEL   "%-24s"+ NOR+YEL+"\n"NOR, blank_string );

        if( ob->max_water_capacity() > 0 )
                line += sprintf( HIC "【饮水】"NOR"：%-24s"+ NOR+YEL+"\n"NOR , tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN));
        else
                line += sprintf( HIC "【饮水】"NOR CYN"：%-24s"+ NOR+YEL+"\n"NOR, blank_string );

        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );

		if (my["born_family"] && my["born_family"] != "没有")
		{
			line += HIW "【性格】：【" + my["character"]+"】";
		}
		else if (stringp(my["born"]) && my["born"])
		{
			line += HIW "【性格】：【" + my["character"]+"】\n";
		}
		else
			line += HIW "  你尚未出生";

		skill_str=keys(me->query("special_skill"));
		line +=HIG"【天赋】："NOR;
		for(i=0; i<sizeof(skill_str); i++)
		{
			line +=HIG"【"+SPECIAL_D(skill_str[i])->name()+HIG"】";
		}
        line += sprintf( YEL "\n" NOR );
        line += sprintf( HIY "【膂力】：" HIW "%2d |%4d  " HIY "【悟性】：" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
                ob->query("str"),
                ob->query_str(),
                ob->query("int"),
                ob->query_int());


        line += sprintf( HIY "【根骨】：" HIW "%2d |%4d  " HIY "【身法】：" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
                ob->query("con"),
                ob->query_con(),
                ob->query("dex"),
                ob->query_dex());
				
		line += sprintf( HIY "【容貌】：" HIW "%2d |%4d  " HIY "【福缘】：" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
                ob->query("per"),
                ob->query_per(),
                ob->query("kar"),
                ob->query_kar());
			
        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );

        line += sprintf( YEL "" HIC "【拳脚】" NOR "%s" HIC "【兵器】" NOR "%s" NOR YEL "\n" NOR,ob->query("opinion/unarmed")? oprank[ob->query("opinion/unarmed")]:CYN "无评价    " NOR,ob->query("opinion/weapon")? oprank[ob->query("opinion/weapon")]:CYN "无评价    " NOR);

        line += sprintf( YEL "" HIC "【内功】" NOR "%s" HIC "【轻功】" NOR "%s" NOR YEL "\n" NOR,ob->query("opinion/force")? oprank[ob->query("opinion/force")]:CYN "无评价    " NOR,ob->query("opinion/dodge")? oprank[ob->query("opinion/dodge")]:CYN "无评价    " NOR);

		line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );
        line += sprintf( YEL "                                                                \n" NOR );
        line += sprintf( YEL "" NOR HIY "   武学宗师： %s" NOR HIY "    任督二脉： %s\n" NOR HIY "   元婴出世： %s" NOR HIY "    生死玄关： %s " NOR YEL "\n" NOR,
                ultrap(ob)?"○":HIC"×",ob->query("breakup")?"○":HIC"×",ob->query("animaout")?"○":HIC"×",ob->query("death")?"○":HIC"×");

        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );

        line += sprintf( YEL "" HIB "【杀生次数】" NOR HIR"%d位"NOR,
                (int)mci["MKS"] + (int)mci["PKS"]);
        line += sprintf( YEL "" HIB "【杀死玩家】" NOR HIR"%d位\n"NOR,
                (int)mci["PKS"]);
        line += sprintf( YEL "" HIB "【有意杀害】" NOR HIR"%d位"NOR,
                (int)mci["WPK"]);

        line += sprintf( YEL "" HIB "【击晕玩家】" NOR HIR"%d位\n"NOR,
                (int)mci["DPS"]);
        line += sprintf( YEL "" HIB "【正派人士】" NOR HIR"%d位"NOR,
                (int)mci["DPS_GOOD"]);
        line += sprintf( YEL "" HIB "【邪派人士】" NOR HIR"%d位"NOR,
                (int)mci["DPS_BAD"]);
        line += YEL "\n" NOR;

        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );

	//	line += HIG "   你目前的★点券★有:( "+HIM+my["suit_point"]+HIG+" )点 "NOR"\n";

        msg = "";
        if( (int)mci["dietimes"])
                msg = sprintf(HIW "   你到目前为止总共到黑白无常那里"
                                "串门%s次。" NOR,
                                chinese_number(mci["dietimes"]))+ "\n";
        if( stringp(mci["last_die"]))
                line += sprintf(HIR "   你最后一次是%s。" NOR,mci["last_die"])+ "\n";
        if( msg != "")
        {
#ifndef LONELY_IMPROVED
                len = color_len(msg);
#endif
                line += sprintf( "%" + sprintf("%d",(64 + len)) + "-s" NOR, msg )+ "\n";
        }
        line += YEL "┗━━━━━━━━━━【个人档案】━━━━━━━┛\n" NOR;

        line += sprintf( HIW "   现实生活的时间：" + ctime( time ) + "。\n"NOR);
        line += sprintf( HIW "   三倍潜能的时间："+ CHINESE_D->chinese_time(me->query("qnvip/times"))+ "。"NOR"\n");
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
指令格式 : score
           score <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。

see also : hp
HELP
    );
    return 1;
}
