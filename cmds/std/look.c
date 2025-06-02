// look.c
#pragma optimize
#pragma save_binary

#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <armor.h>
#include <zjmud.h>

#define SHOW_IMMEDIATELY	0
#define RETURN_RESULT	 1
#define TIME_TICK1 ((time()-900000000)*60)

inherit F_CLEAN_UP;

int look_room(object me, object env, int brief);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string look_equiped(object me, object obj, string pro);
string look_all_inventory_of_room(object me, object env, int ret_str);
string gettof(object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
	HIG "����������" NOR,     // 0    exp: 0--10000 
	HIG "����������" NOR,     // 1    exp: 10000--20000  
	HIG "����������" NOR,     // 2    exp: 20000--30000 
	HIG "����������" NOR,     // 3    exp: 30000--40000
	HIB "������Բ��" NOR,     // 4    exp: 40000--50000
	HIB "����������" NOR,     // 5    exp: 50000--60000
	HIB "����������" NOR,     // 6    exp: 60000--70000
	HIB "����������" NOR,     // 7    exp: 70000--80000
	HIB "����������" NOR,     // 8    exp: 80000--90000
	HIB "������Բ��" NOR,     // 9    exp: 120000--160000
	HIB "�ھ�������" NOR,     // 10   exp: 160000--250000
	HIB "�ھ�������" NOR,     // 11   exp: 250000--350000
	HIB "�ھ�������" NOR,     // 12   exp: 350000--550000
	HIB "�ھ�������" NOR,     // 13   exp: 550000--750000
	HIB "�ھ���Բ��" NOR,     // 14   exp: 750000--900000
	HIM "����������" NOR,     // 15   exp: 900000--1150000
	HIM "����������" NOR,     // 16   exp: 1150000--1350000
	HIM "����������" NOR,     // 17   exp: 1350000--1500000
	HIM "����������" NOR,     // 18   exp: 1500000--1700000
	HIM "������Բ��" NOR,     // 19   exp: 1700000--1900000
	HIM "�������" NOR,     // 20   exp: 1900000--2150000
	HIM "�������" NOR,     // 21   exp: 2150000--2400000
	HIM "�������" NOR,     // 22   exp: 2400000--2550000
	HIM "�������" NOR,     // 23   exp: 2550000--2700000
	HIM "���Բ��" NOR,     // 24   exp: 2700000--2850000
	HIM "����������" NOR,     // 25   exp: 2850000--3000000
	HIY "����������" NOR,     // 26   exp: 3000000--3500000
	HIY "����������" NOR,     // 27   exp: 3500000--4000000
	HIY "����������" NOR,     // 28   exp: 4000000--5250000
	HIY "������Բ��" NOR,     // 29   exp: 5250000--7000000
	HIY "����������" NOR,     // 30   exp: 7000000--7500000
	HIY "����������" NOR,     // 31   exp: 7500000--8250000
	HIY "����������" NOR,     // 32   exp: 8250000--9000000
	HIY "����������" NOR,     // 33   exp: 9000000--12000000
	HIY "������Բ��" NOR      // 34   exp: 12000000--15000000
	HIY "���������" NOR,     // 35   exp: 2850000--3000000
	HIY "���������" NOR,     // 36   exp: 3000000--3500000
	HIY "���������" NOR,     // 37   exp: 3500000--4000000
	HIY "���������" NOR,     // 38   exp: 4000000--5250000
	HIY "�����Բ��" NOR,     // 39   exp: 5250000--7000000
	HIY "����������" NOR,     // 40   exp: 2850000--3000000
	HIY "����������" NOR,     // 41   exp: 3000000--3500000
	HIY "����������" NOR,     // 42   exp: 3500000--4000000
	HIY "����������" NOR,     // 43   exp: 4000000--5250000
	HIY "������Բ��" NOR,     // 44   exp: 5250000--7000000
	HIY "ʥ�ʡ�����" NOR,     // 45   exp: 2850000--3000000
	HIY "ʥ�ʡ�����" NOR,     // 46   exp: 3000000--3500000
	HIY "ʥ�ʡ�����" NOR,     // 47   exp: 3500000--4000000
	HIY "ʥ�ʡ�����" NOR,     // 48   exp: 4000000--5250000
	HIY "ʥ�ʡ�Բ��" NOR,     // 49   exp: 5250000--7000000
	HIY "��������" NOR,     // 50   exp: 2850000--3000000
	HIY "���𡤳���" NOR,     // 51   exp: 3000000--3500000
	HIY "��������" NOR,     // 52   exp: 3500000--4000000
	HIY "���𡤺���" NOR,     // 53   exp: 4000000--5250000
	HIY "����Բ��" NOR,     // 54   exp: 5250000--7000000
});
int *look_exp=({
	10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,200000,300000,400000,500000,600000,
	700000,800000,900000,1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,9000000,
	10000000,20000000,30000000,40000000,50000000,60000000,70000000,80000000,90000000,100000000,
    150000000,200000000,250000000,300000000,350000000,400000000,450000000,500000000,550000000,
    600000000,650000000,700000000,750000000,800000000,850000000,900000000,9500000000,
});
string *heavy_level_desc= ({
	"����",
	"����",
	"����",
	"����",
	"����",
	"����"	
});
string *first_name = ({ YEL,HIY,HIM,HIG,HIW,HIR});
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object obj;
	object env;
	int result;
	string objid, where;

	if (! arg) result = look_room(me, environment(me), 0);
	else
	{
		if (sscanf(arg, "%s of %s", objid, where) == 2)
		{
			if (where == "here")
			obj = present(objid, environment(me));
			else
			if (where == "me")
			obj = present(objid, me);
			else
			{
				env = present(where, environment(me));
				if (! objectp(env))
				return notify_fail("��Ҫ������Ķ�����\n");
				obj = present(objid, env);
				if (env->is_character() && env != me)
				{
					if (! objectp(obj) ||
							! obj->query("equipped") &&
							env->query_temp("handing") != obj)
					return notify_fail("���˺���û��©�������뿴�Ķ�������\n");
					message("vision", me->name() + "�������" + obj->name() + "����һ�������֪���ڴ�ʲô���⡣\n", env);
					message("vision", me->name() + "����" + env->name() + "��" +obj->name() + "����һ�������֪���ڴ�ʲô���⡣\n",
					environment(me), ({ me, env }));
				}
			}

			if (! obj)
			return notify_fail("����û������������\n");
		}	

		if( obj || (obj = find_player(arg)) || (obj = present(arg, environment(me))) || (obj = present(arg, me))|| (obj = find_object(arg)) )
		{
			if( obj->is_character() && ! obj->is_corpse()) result = look_living(me, obj);
			else result = look_item(me, obj);
		} else result = look_room_item(me, arg);
	}

	return result;
}

int look_room(object me, object env, int brief)
{
	int i;
	mapping exits,descs,actlist;
	string str, *dirs,*desc;
	object room;
	mixed *cmds;
	string *mapped;

	if( !env ) {
		tell_object(me, "������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
		me->move("/d/wizard/guest_room");
		return 1;
	}

	if( !brief )
	{
		str = sprintf(ZJTITLE"%s\n"ZJLONG "%s",env->short(),replace_string(env->long(),"\n",""));
	} else
	{
		str = sprintf(ZJTITLE"%s\n"ZJLONG"������������Ϣ�����Ρ�����"+ZJURL("cmds:unset brief")+"ȡ������"NOR,env->short());
	}

	if (mapp(exits = env->query("exits")))
	{
		dirs = keys(exits);
		dirs -= ({ 0 });
		str += "\n" + ZJEXIT;
        str += "save:"HIR"��浵��"NOR+ZJSEP;
		str += "help kuaijie:"HIR"��ݹ���"NOR+ZJSEP;
		str += "use quest sss:"HIG"�Զ�ʦ��"NOR+ZJSEP;
		str += "help mapb:"HIY"Ԧ�����"NOR+ZJSEP;

		if (!me->query("map_all")&&env->query("outdoors")&&env->query("outdoors")!="hell"&&me->query("out_family")&&me->query("id")!="a3901500")
		{
			mapped = me->query("map/"+env->query("outdoors"));
			if (!arrayp(mapped)) mapped = ({ });
			if (member_array(env->short(), mapped)==-1)
			str += "map here:"HIG"��  ͼ"NOR+ZJSEP;
			//str += "use quest sss;accept quest;eat bt dan;jiqu:"HIG"�Զ�ʦ��"NOR+ZJSEP;
		}
		if (FUBEN_D->query_where(base_name(env)))
		{
			str += "fuben:"HIG"�����б�"NOR+ZJSEP;
		}
		if (env->query("price_build"))
		{
			str += "crroom:"HIM"�����԰"NOR+ZJSEP;
		}
		
		if (env->query("resource/fish")&&present("diao gan",me)&&present("yu er",me))
		{
			str += "fish:"HIM"����"NOR+ZJSEP;
			str += "draw diao gan:"HIG"����"NOR+ZJSEP;
			str += "halt:"HIR"�ж�"NOR+ZJSEP;
		}
		if (env->query("short")=="�����" || env->query("short")=="��������")
		{
			str += "quest1:"HIC"ʣ��ʱ��"NOR+ZJSEP;
		}
		if(wizardp(me))
		{
			str += "help kuaijie1:"HIC"��  ��"NOR+ZJSEP;
			str += "update here:���´˵�"+ZJSEP;
			//			str += ZJSEP;
			//			str += "full:"HIM"�ָ�״̬"NOR+ZJSEP;
		}
		
		//str += "help ts:"HIM"��ɫ����"NOR+ZJSEP;
		
		for (i=0;i<sizeof(dirs);i++)
		{
			if(!room=find_object(exits[dirs[i]]))  room=load_object(exits[dirs[i]]);
			if(room)  str+=sprintf("%s:%s",dirs[i],room->query("short"));
			if(i<(sizeof(dirs)-1)) str += ZJSEP;
		}
	}
	if (mapp(actlist = env->query("action_list")))
	{
		if(!mapp(exits))
		str += "\n" + ZJEXIT;
		else
		str += ZJSEP;
		dirs = keys(actlist);
		dirs -= ({ 0 });
		for (i=0;i<sizeof(dirs);i++)
		{
			str += sprintf("%s:%s",actlist[dirs[i]],dirs[i]);
			if(i<(sizeof(dirs)-1)) str += ZJSEP;
		}
	}

	str += look_all_inventory_of_room(me, env, RETURN_RESULT);

	if (mapp(descs = env->query("item_desc")))
	{
		str += "\n"+ZJOBIN;
		desc = keys(descs);
		for (i=0;i<sizeof(desc);i++)
		{
			str += desc[i] + ":look " + desc[i];
			if(i<(sizeof(desc)-1)) str += "$zj#";
		}
	}
	tell_object(me, str+"\n");

	return 1;
}

string desc_of_objects(object *obs,object me)
{
	int i,n;
	string  str,rid,*id,rname;
	string name2;
	name2 = first_name[random(sizeof(first_name))];
	if (obs && sizeof(obs) > 0)
	{
		str = "\n" + ZJOBIN;
		for (i = 0; i < sizeof(obs); i++)
		{
			if(obs[i]->query_amount())
			rname = obs[i]->query("name")+"("+obs[i]->query_amount()+")";
			else
			rname = obs[i]->query("name");

			if(playerp(obs[i]))
			str += HIC+rname+NOR":look "+file_name(obs[i]);
			else if(obs[i]->query("id") == me->query("quest/id") )
			str += name2+rname+NOR":look "+file_name(obs[i]);
			else
			str += rname+":look "+file_name(obs[i]);
			if(i<(sizeof(obs)-1)) str += ZJSEP;
		}
		return str;
	}

	return "";
}

string look_all_inventory_of_room(object me, object env, int ret_str)
{
	object *inv;
	object *obs;

	string  str;

	if (! env || ! me) return "";

	inv = all_inventory(env);
	if (! sizeof(inv)) return "";

	str = "";

	obs = filter_array(inv, (: $(me) != $1 && userp($1) && $(me)->visible($1) :));
	str += desc_of_objects(obs,me);

	obs = filter_array(inv, (: $(me) != $1 && !userp($1) && $1->is_character() && $(me)->visible($1) :));
	str += desc_of_objects(obs,me);

	obs = filter_array(inv, (: !$1->is_character() :), me);
	str += desc_of_objects(obs,me);

	if (!ret_str)
	tell_object(me, str);

	return str;
}

string get_inv_act(object me, object obj)
{
	mapping acts;
	string act,look_msg3="";

	if(present(obj,me))
	{
		if (obj->query("equipped")&&stringp(obj->query("skill_type")))
		look_msg3 += "���� "+obj->query("name")+":unwield "+file_name(obj)+ZJSEP;
		else if (obj->query("equipped")&&stringp(obj->query("armor_type")))
		look_msg3 += "�ѵ� "+obj->query("name")+":remove "+file_name(obj)+ZJSEP;
		else if (stringp(obj->query("skill_type")))
		look_msg3 += "װ�� "+obj->query("name")+":wield "+file_name(obj)+ZJSEP;
		else if (stringp(obj->query("armor_type")))
		look_msg3 += "���� "+obj->query("name")+":wear "+file_name(obj)+ZJSEP;
		else if (obj==me->query_temp("is_riding"))
		look_msg3 += "���� "+obj->query("name")+":unride "+file_name(obj)+ZJSEP;	

		if (obj->is_item_make())
		{
			if(obj->query("consistence")<100&&me->query("zjvip/times"))
			look_msg3 += "���� "+obj->query("name")+":repairv "+file_name(obj) +ZJSEP;

			look_msg3 += "ǿ�� "+obj->query("name")+":enhance "+file_name(obj) + " with jin sha" +ZJSEP;
			look_msg3 += "ʥ�� "+obj->query("name")+":san "+file_name(obj)  + ZJSEP;
			look_msg3 += "��͸ "+obj->query("name")+":imbue "+file_name(obj)  + ZJSEP;
			if(obj->query("magic/tessera"))
			look_msg3 += "ժ�� "+obj->query("magic/tessera")+":zhaichu "+file_name(obj)  + ZJSEP;
			else
			look_msg3 += "��Ƕ "+obj->query("name")+":enchase "+file_name(obj)  + ZJSEP;
		}

		if(obj->query("can_be_enchased")&&obj->query("enchased_need"))
		look_msg3 += "�ϳ� "+(obj->query("can_be_enchased"))->query("name")+":combine "+file_name(obj)+ZJSEP;

		if(acts = obj->query("action_list"))
		{
			foreach(act in keys(acts))
			look_msg3 += act +" "+obj->query("name")+":"+acts[act]+ZJSEP;
		}
		if (obj->query("food_remaining"))
		look_msg3 += "�� "+obj->query("name")+":eat "+file_name(obj)+ZJSEP;
		else if (obj->query("only_do_effect"))
		look_msg3 += "ʹ�� "+obj->query("name")+":use "+file_name(obj)+ZJSEP;
		else if (obj->query("liquid/remaining"))
		look_msg3 += "�� "+obj->query("name")+":drink "+file_name(obj)+ZJSEP;
		else if (obj->query("liquid/bei"))
		look_msg3 += "�� "+obj->query("name")+":drinkjiu2 "+file_name(obj)+ZJSEP;	//�¾ƺȷ�
		else if (obj->query("skill") )
		look_msg3 += "�ж� "+obj->query("name")+":study "+file_name(obj)+ZJSEP;

		else if (obj->query("id")=="kuihua baodian")
		look_msg3 += "�ж� "+obj->query("name")+":study kuihua baodian"+ZJSEP;

		look_msg3 += "�鿴 "+obj->query("name")+":lookmore "+file_name(obj)+ZJSEP;

		if(objectp(present("chuwu dai",me)))
		look_msg3 += "���� "+present("chuwu dai",me)->query("name")+":mystore put "+file_name(obj)+ZJSEP;
		
		if(objectp(present("du wan",me)))			
		look_msg3 += HIG"Ͷ�� "NOR+obj->query("name")+":drug du wan in "+obj->query("id")+" "ZJSEP;
		
		look_msg3 += "չʾ "+obj->query("name")+":showitem "+file_name(obj)+ZJSEP;
		look_msg3 += "�ֳ� "+obj->query("name")+":hand "+file_name(obj)+ZJSEP;
		look_msg3 += "���� "+obj->query("name")+":sellob "+file_name(obj)+ZJSEP;
		look_msg3 += "���� "+obj->query("name")+":drop "+file_name(obj)+ZJSEP;
		look_msg3 += HIC"<���ر���>"NOR":i ";

	}
	return look_msg3;
}

int look_item(object me, object obj)
{
	object hob;
	mixed *inv;
	mapping acts,count;
	mapping equiped;
	mapping unit;
	string short_name;
	mapping du;
	string act,str;
	string *dk;
	string type="";
	int i;
	int line;
	count   = ([]);
	unit    = ([]);
	equiped = ([]);

	//����
	if (obj->query("ok_jianding") && (obj->query("weapon_prop") || obj->query("armor_prop")))
	{
		type = obj->query("jianding") ? HIG"  ���Ѽ���"NOR : HIR"  ��������"NOR;
	}
	if (obj->query("spoil"))
		type = HIR"(����)"NOR;
	
	
	str = ZJOBLONG+obj->short()+"\n";
	str += "һһһһһһһһһһһһһһһһһһһһһһ\n";
	str += obj->long();
	if(obj->long()=="") return 1;
	str = ZJOBLONG+obj->short()+(type)+ZJBR"һһһһһһһһһһһһһһһһһһһһһһһ"ZJBR+obj->long();
	if(obj->query("id")=="board" ||  obj->query("id")=="mailbox" || obj->query("id")=="corpse" || obj->query("id")=="sleepbag" || obj->query("id")=="skeleton")
	line=0;
	else
	line=1;
	if((int)obj->query("value")==0)
	{
		line=0;  
	}
	if(!present(obj,me)&&(obj->query("id")=="coin"||obj->query("id")=="silver"||obj->query("id")=="gold"||obj->query("id")=="cash"))
	{
		str = replace_string(str,"\n",ZJBR);
		str += "\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "������:get " + file_name(obj);
		write(str+"\n");
		return 1;
	}
	if(obj->query("id")=="newbie" ) return 1;
	if(line)
	{
		str += "һһһһһһһһһһһһһһһһһһһһһһ\n";
	}
	/*
	//����Ļ�
	if(obj->query("poison_type")=="poison")
	{
		if(mapp(du=obj->query("poison")))
		{
			str += HIG"���ࡡ��: "+du["name"]+NOR"\n";
			str += HIG"��������: "+chinese_number((int)du["level"])+NOR"\n";
			str += HIG"�������ȡ�: "+chinese_number((int)du["duration"])+NOR"\n";
			str += HIG"�������ߡ�: "+du["id"]+NOR"\n";
			if(obj->query("value"))
			{
				str += YEL"���ۡ�ֵ��: "+MONEY_D->money_str((int)obj->query("value"))+NOR"\n";
			}
		}
	}
	else
	{
		if(obj->item_owner() && obj->apply_damage())
		{
			str += YEL"�������顿: "+obj->weapon_exp()+NOR" / "HIY+obj->level_max_exp(obj->weapon_level())+NOR" / "HIY+chinese_number(obj->level_now(obj->weapon_level()))+NOR"��\n"; 
			if(obj->query("magic/imbue_ob"))
				str += MAG"��ʥ������: ��ʥ������"+obj->query("magic/imbue_name")+"��͸"+NOR"\n";
			else
				str += MAG"��ʥ������: δʥ��"+NOR"\n";
			str += HIM"������͸��: "+chinese_number((int)obj->query("magic/imbue"))+NOR"\n";
			str += HIR"��Ѫ���ȡ�: "+chinese_number((int)obj->query("combat/MKS")+(int)obj->query("combat/PKS"))+NOR"\n"; 
		}
		else if(obj->item_owner())
		{
			str += HIY"���ȡ�����: "+chinese_number((int)obj->armor_level())+NOR"\n"; 
		}
		if(obj->query("weapon_prop/damage"))
		{
			str += HIR"����������: "+chinese_number((int)obj->query("weapon_prop/damage"))+NOR"\n";
		}
		if(obj->query("armor_prop/unarmed_damage"))
		{
			str += HIR"����������: "+chinese_number((int)obj->query("armor_prop/unarmed_damage"))+HIR"����--<ע����������Ч>\n"NOR;
		}
		if(obj->query("power"))
		{
			str += HIR"���ƻ�����: "+chinese_number((int)obj->query("power"))+NOR"\n";
		}
		if(obj->query("accuracy"))
		{
			str += HIG"����ȷ�ȡ�: "+chinese_number((int)obj->query("accuracy"))+NOR"\n";
		}
		if(obj->query("armor_prop/armor"))
		{
			str += HIG"����������: "+chinese_number((int)obj->query("armor_prop/armor"))+NOR"\n";
		}
		if(obj->query("armor_prop/warm"))
		{
			str += HIG"����ů�ȡ�: "+chinese_number((int)obj->query("armor_prop/warm"))+NOR"\n";
		}
		if(obj->query("armor_buwei"))
		{
		str += GRN"������λ��: "+obj->query("armor_buwei")+NOR"\n";
		}
		if(obj->query("material") && !obj->item_owner())
		{
			str += GRN"���ġ��ʡ�: "+to_chinese(obj->query("material"))+NOR"\n";
		}
	
		if(obj->query("value") && !obj->item_owner() && line)
		{
			str += YEL"���ۡ�ֵ��: "+MONEY_D->money_str((int)obj->query("value"))+NOR"\n";
		}
		if(obj->item_owner() && obj->apply_damage())
		{
			if (me->query("can_summon/"+obj->query("id")))
			{
				str += GRN"�������⡿: "GRN"�Ѱ�\n"NOR;
			}
			else
			{
				str += GRN"�������⡿: "WHT"δ���� < Ѱ������ʦ���� > \n"NOR;
			}   
		}	 
	}
*/
	while (mapp(obj->query_temp("daub")))
	{
		if (! obj->query_temp("daub/poison/remain"))
		// no poison remain now
		break;

		if (obj->query_temp("daub/poison/id") == me->query("id"))
		{
			str += HIG "�㷢�������滹�������Ƶ�" + obj->query_temp("daub/poison/name") + HIG "�ء�"NOR"\n";
			break;
		}

		if (obj->query_temp("daub/who_id") == me->query("id"))
		{
			str += HIG "�����滹�������ֲ��µ�" + obj->query_temp("daub/poison/name") + HIG "�ء�"NOR"\n";
			break;
		}

		if (random(4) && random((int)me->query_skill("poison", 1)) < 30)
		// nothing was worked out
		break;

		str += HIG "��Ȼ���㷢�������ƺ�����һЩ����ӫ��";
		if (me->query_skill("poison", 1) >= 120)
		{
			str += "��������" + obj->query_temp("daub/poison/name");
		}

		str += "��"NOR"\n";
		break;
	}

	if(obj->query("weapon_prop/damage"))
	{
		str += HIR"������������"+chinese_number((int)obj->query("weapon_prop/damage"))+NOR"\n";
	}
	if(obj->query("armor_prop/unarmed_damage"))
	{
		str += HIR"������������"+chinese_number((int)obj->query("armor_prop/unarmed_damage"))+NOR"\n";
	}
	if(obj->item_owner() && obj->apply_damage()&&obj->query("magic/power"))
	{
		str += HIM"��ħ��������"+chinese_number((int)obj->query("magic/power"))+NOR"\n";
	}
	if(obj->query("armor_prop/armor"))
	{
		str += HIG"������������"+chinese_number((int)obj->query("armor_prop/armor"))+NOR"\n";
	}

	if (obj->query("consistence"))
	str += sprintf("���;öȡ���" WHT "%d%%"NOR"\n", obj->query("consistence"));

	inv = all_inventory(obj);
	if (!sizeof(inv))
	{
		str = replace_string(str,"\n",ZJBR);
		if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];
		if(!obj->query("no_get")&&!present(obj,me)&&present(obj,environment(me)))
		{
			str += "\n"+ZJOBACTS2+ZJMENUF(3,3,10,30);
			str += "������:get " + file_name(obj);
			if(obj->is_cutable())
			{
				str += ZJSEP"��:cut " + obj->query("id");
			}
		}
		else if(acts = obj->query("acts_list"))
		{
			str += "\n"+ZJOBACTS2+ZJMENUF(3,3,10,30);
			foreach(act in keys(acts))
			str += act +" "+obj->query("name")+":"+acts[act] + ZJSEP;
		}

		if(present(obj,me))
		{
			str += "\n"+ZJOBACTS2+ZJMENUF(3,3,10,30);
			str += get_inv_act(me,obj)+"\n";
		}
		if(str==ZJOBLONG) return 1;
		message("vision", str+"\n", me);
		return 1;
	}

	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
	str = str[0..(strlen(str)-5)];
	str += "\n";

	str += ZJOBACTS2+ZJMENUF(3,3,10,30);
	if(present(obj,me))
	{
		str += get_inv_act(me,obj);
	}
	if(!present(obj,me)&&present(obj,environment(me)))
	{
		str += "������:get " + file_name(obj);
		for(i=0;i<sizeof(inv);i++)
		{
			str += ZJSEP+inv[i]->query("name")+(inv[i]->query_amount()?"("+inv[i]->query_amount()+")":"")+":get "+file_name(inv[i])+" from " + file_name(obj);
		}
	}
	if(obj->is_cutable())
	{
		str += ZJSEP"ϸ�½���:cut " + obj->query("id");
		str += ZJSEP"ն��ʾ��:cut head from " + obj->query("id");
	}
	if(acts = obj->query("acts_list"))
	{
		foreach(act in keys(acts))
		str += ZJSEP + act +" "+obj->query("name")+":"+acts[act];
	}

	str += "\n";
	if (strlen(str) > 4096)
	me->start_more(str);
	else
	message("vision", str, me);
	return 1;
}
//�������۴���
string gettof(object ob)
{
	int exp_temp ,i;
	exp_temp=(int)ob->query("combat_exp");
	for(i=0;i<sizeof(tough_level_desc);i++)
	{
		if(exp_temp<500)
		{
			return HIR+"����һ��"+NOR;
		}
		if((i+1)==sizeof(tough_level_desc))
		{
			return tough_level_desc[i];
		}
		if(exp_temp>=look_exp[i] && exp_temp<look_exp[i+1])
		{
			return tough_level_desc[i+1];
		}
		
	}
	return HIR+"��ɲ�"+NOR;
}
string look_equiped(object me, object obj, string pro)
{
	mixed *inv;
	string str;
	string subs;
	object hob;
	int i;
	int n;

	inv = all_inventory(obj);
	n = 0;

	str = "";
	subs = "";
	for (i = 0; i < sizeof(inv); i++)
	{
		if(!inv[i]->query("skill_type")&&inv[i]->query("armor_type")!="armor"&&inv[i]->query("armor_type")!="cloth")
		continue;
		switch (inv[i]->query("equipped"))
		{
		case "wielded":
			n++;
			subs = HIC "�I" NOR + inv[i]->short() + "\n" + subs;
			break;

		case "worn":
			n++;
			subs += HIC "�I" NOR + inv[i]->short() + "\n";
			break;

		default:
			break;
		}
	}

	if (n)
	str += pro + "װ���ţ�\n" + subs;

	if (objectp(hob = obj->query_temp("handing")) &&
			(me == obj || obj->query_weight() > 200))
	{
		int mad;

		// dress nothing but handing a cloth !
		mad = (! objectp(obj->query_temp("armor/cloth")) &&
		hob->query("armor_type") == "cloth");

		str = pro + "����" + (mad ? "ȴ" : "" ) + "����һ" +
		(hob->query_amount() ? hob->query("base_unit")
		: hob->query("unit")) +
		hob->name() +
		(mad ? "�����ˣ�һ���Ƿ��ˣ�\n" : "��\n") + str;
	}

	if (playerp(obj) &&! objectp(obj->query_temp("armor/cloth")))
	{
		str = pro + "����û�д��·�����\n" + str;
	}

	return str;
}

string description(object obj)
{
	if (playerp(obj))
	{
		int per;
		int age;
		per = obj->query_per();
		age = obj->query("age");
		if (obj->query("special_skill/youth")) age = 14;
		if ((string) obj->query("gender") == "����" || (string) obj->query("gender") == "����")
		{
			if (obj->query("id")=="luoyun")
			return HIG"���Ǳ���Ϸ��˧���ˣ�����ò��Ż�Ϊһ���ǧ�Ų��ӡ�\n"NOR;	  
			if (per >=50)
			return HIG"����һ���������ȣ��ɷ���ǣ���ֹ������\n"NOR;
			if (per <= 50 && (per > 40))
			return HIG"����������ˬ���Ǹ����棬�������ˡ�\n"NOR;
			if (per <= 40 && (per > 37))
			return HIG"���ڷ����ʣ��������������������ٷ硣\n"NOR;
			if (per <= 37 && (per > 36))
			return HIG"����Ʈ�ݳ������������ס�\n"NOR;
			if (per <= 36 && (per > 35))
			return HIG"�����������񣬷�ױ����������������\n"NOR;
			if (per <= 35 && (per > 34))
			return HIG"���ڷ�������Ŀ�����ǣ����˹�Ŀ������\n"NOR;
			if (per <= 34 && (per > 33))
			return HIY"���ڷ����촽�����˿��Σ���ֹ�������ޡ�\n"NOR;
			if (per <= 33 && (per > 32))
			return HIY"����˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ���\n"NOR;
			if (per <= 32 && (per > 31))
			return HIY"���ھٶ���������ˮ�����̷��飬������������Ŀ�⡣\n"NOR;
			if (per <= 31 && (per > 30))
			return HIY"����˫�۹⻪Ө��͸���������ǵĹ�â��\n"NOR;
			if (per <= 30 && (per > 29))
			return HIY"����Ӣ���������������Ρ�\n"NOR;
			if (per <= 29 && (per > 28))
			return MAG"����Ŀ�Ƶ��ᣬ�ߴ�ͦ���������Ķ���\n"NOR;
			if (per <= 28 && (per > 27))
			return MAG"�����������£�����˹�ģ���ֹ�ʶȡ�\n"NOR;
			if (per <= 27 && (per > 26))
			return MAG"���ý�ü��Ŀ��Ӣ�˲������Ǳ�����\n"NOR;
			if (per <= 26 && (per > 25))
			return MAG"��������Ũ�ף����۱��ǣ��������ݣ������㵹��\n"NOR;
			if (per <= 25 && (per > 24))
			return MAG"����ü��˫�����������ǣ�Ӣͦ���ڡ�\n"NOR;
			if (per <= 24 && (per > 23))
			return CYN"���û���������׳��������Ӣ�˲�����\n"NOR;
			if (per <= 23 && (per > 22))
			return CYN"���÷�ɫ��𪣬�촽ī����˹������\n"NOR;
			if (per <= 22 && (per > 21))
			return CYN"����Ũü���ۣ��ߴ�ͦ�Σ�����������\n"NOR;
			if (per <= 21 && (per > 20))
			return CYN"���ñ�ֱ�ڷ��������������Գ������Ը�\n"NOR;
			if (per <= 20 && (per > 19))
			return CYN"����üĿ���㣬�����󷽣�һ���˲š�\n"NOR;
			if (per <= 19 && (per > 18))
			return YEL"������Բ���������ڷ����Ǹ񲻷���\n"NOR;
			if (per <= 18 && (per > 17))
			return YEL"������òƽƽ�������������ʲôӡ��\n"NOR;
			if (per <= 17 && (per > 16))
			return YEL"���ð����Բ���������⣬���ζ��ࡣ\n"NOR;
			if (per <= 16 && (per > 15))
			return YEL"�����ͷ���룬����һ���Ͳ����øС�\n"NOR;
			if (per <= 15 && (per > 14))
			return YEL"����������ݣ�����ݹǣ�����Ҫ�����Ρ�\n"NOR;
			if (per <= 14 && (per > 13))
			return RED"���÷�ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц��\n"NOR;
			if (per <= 13 && (per > 12))
			return RED"������ü���ۣ�������ߣ�������״��\n"NOR;
			if (per <= 12 && (per > 11))
			return RED"���������Ƥ��ͷ���������˲����ٿ��ڶ��ۡ�\n"NOR;
			if (per <= 11 && (per > 10))
			return RED"�����������죬������ף�����ޱȡ�\n"NOR;
			if (per <= 10)
			return RED"����ü����б����ͷѢ�ţ�����������\n"NOR;
			return "�����е�Բ�ס���ˡ�\n";
		}
		else
		{
			if (per >=40) 
			return HIW"�������������ܣ������ƻã��Ѳ����Ƿ������\n"NOR;
			if (per <= 39 && (per > 38))
			return HIG"�����������ɣ���մһ˿�̳���\n"NOR;
			if (per <= 38 && (per > 37))
			return  HIG"���ڲ�����ϼ���������񣬻����������ӡ�\n"NOR;
			if (per <= 37 && (per > 36))
			return HIG"�����������������Ż���ɽ�����˼�֮���ס�\n"NOR;
			if (per <= 36 && (per > 35))
			return HIG"���ڷ����۰ף�Ӥ��С�ڣ�üĿ���飬�·�̫�����١�\n"NOR;
			if (per <= 35 && (per > 34))
			return HIG"�����������ģ����ȷ�����������Σ��۹�֬�ޡ�\n"NOR;
			if (per <= 34 && (per > 33))
			return HIY"�����������ã�ü��ī���������Ұ꣬Ŀ���ﲨ��\n"NOR;
			if (per <= 33 && (per > 32))
			return HIY"���ڷ�����ü�����溬�����������ݣ�ת�ζ��顣\n"NOR;
			if (per <= 32 && (per > 31))
			return HIY"����üĿ�续������ʤѩ�����ν�����߻���\n"NOR;
			if (per <= 31 && (per > 30))
			return HIY"���ڽ����������������£�����ܳ������㡣��\n"NOR;
			if (per <= 30 && (per > 29))
			return HIY"�����о���毻���ˮ���ж����������磬��̬��ǧ��\n"NOR;
			if (per <= 29 && (per > 28))
			return MAG"���ý�С���磬��������������������ˡ�\n"NOR;
			if (per <= 28 && (per > 27))
			return MAG"����Ѽ��������������ü���ڷ����٣��������֡�\n"NOR;
			if (per <= 27 && (per > 26))
			return MAG"��������ϸ����������������Ķ��ˣ�������ɡ�\n"NOR;
			if (per <= 26 && (per > 25))
			return MAG"���÷���ϸ������欶��ˣ�����һ�����������ѡ�\n"NOR;
			if (per <= 25 && (per > 24))
			return MAG"���÷��۰���������ҩ���̣����￴����\n"NOR;
			if (per <= 24 && (per > 23))
			return CYN"������������Ŀ����ˮ��ǧ�����ġ�\n"NOR;
			if (per <= 23 && (per > 22))
			return CYN"�����������ģ�����Ө͸��������˼��\n"NOR;
			if (per <= 22 && (per > 21))
			return CYN"������Ц��Ȼ����Լ���ˡ�\n"NOR;
			if (per <= 21 && (per > 20))
			return CYN"�������滨��¶������������\n"NOR;
			if (per <= 20 && (per > 19))
			return CYN"���÷��˳������������ˡ�\n"NOR;
			if (per <= 19 && (per > 18))
			return YEL"���ü���΢�ᣬ�ŵ��������¿��ˡ�\n"NOR;
			if (per <= 18 && (per > 17))
			return YEL"�����䲻���£���Ҳ�׾�����Щ����֮����\n"NOR;
			if (per <= 17 && (per > 16))
			return YEL"���������С�������޹⣬��������\n"NOR;
			if (per <= 16 && (per > 15))
			return  YEL"���øɻƿ��ݣ���ɫ���ƣ�����Ů��ζ��\n"NOR;
			if (per <= 15 && (per > 14))
			return YEL"�����������Ƥɫ�ֺڣ���ª������\n"NOR;
			if (per <= 14 && (per > 13))
			return RED"����һ�����������һ����û�øС�\n"NOR;
			if (per <= 13 && (per > 12))
			return RED"������С�綹��üëϡ�裬�����צ������������\n"NOR;
			if (per <= 12 && (per > 11))
			return RED"���ð���ü�������ۣ���Ƥ�Ʒ�������һ�������¡�\n"NOR;
			if (per <= 11 && (per > 10))
			return RED"�������б�ۣ���ɫ�Ұܣ�ֱ����һ�㡣\n"NOR;
			return "���ú������е�����Ү��\n";

		}
	} else
	if (! obj->query("can_speak") && living(obj))
	{
		if (! obj->query_temp("owner"))
		return "��һֻδ��ѱ�����������۹������ǽ��ĺ͵��⡣\n";
		else
		return "��һֻ��" + obj->query_temp("owner_name") +
		"ѱ����������һ������ѱ�����ӡ�\n";
	}

	return "";
}

string desinq(object me,object obj)
{
	mapping inq;
	string tmpinq,str,*jiaoliu;
	int i;

	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	if(obj->is_quester())
	{
		if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
		str += "��������:ask "+obj->query("id")+" about ����"ZJSEP; 
		str += "��ϯ����:ask "+obj->query("id")+" about ��ϯ����"ZJSEP; 
	}
	if(mapp(inq = obj->query("inquiry"))) 
	{
		jiaoliu = sort_array( keys(inq), (: strcmp :) );
		for(i=0; i<sizeof(jiaoliu); i++)
		{
			if(sscanf(jiaoliu[i],"#%*d-%s",tmpinq)!=2)
			tmpinq = jiaoliu[i];
			str += tmpinq+":ask "+obj->query("id")+" about "+jiaoliu[i]; 
			if(i<(sizeof(jiaoliu)-1)) str += ZJSEP;
		}
	}
	if(obj->query("id")=="nian shou")
	{
		str += "�ӱ���:duobao"ZJSEP;
	}
	if(obj->is_knower())
	{
		if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
		str += "������Ϣ:ask "+obj->query("id")+" about ��Ϣ"; 
	}
	if(str==(ZJOBACTS+ZJMENUF(1,4,10,32))) str = "";
	return str+"\n";
}

string getact(object me,object obj)
{
	mapping inq;
	string str,*jiaoliu;
	int i;

	if(mapp(inq = obj->query("inquiry"))&&inq!=([])||obj->is_knower()||obj->is_quester()) 
	str = ZJOBACTS2+ZJMENUF(3,4,10,32);
	else
	str = ZJOBACTS2+ZJMENUF(4,4,10,32);

	if(obj->is_vendor())
	{
		str += "����:list"ZJSEP; 
	}
	if(present("shua zi",me)&&present("xie you",me))
	{
		str += "��Ь:caxie " + obj->query("id")+ZJSEP;
	}
	if(present("mian ju",me))
	{
		str += HIC"����:pretend " + obj->query("id")+ZJSEP;
		str += HIC"ȡ������:pretend none"NOR +ZJSEP;
	}
	if(me->query("p_master/id")==obj->query("id"))
	{
		str += "�밲:learnto master " + file_name(obj)+ZJSEP;
	}
	if(obj->query("p_master/id")==me->query("id"))
	{
		str += "ָ��:learnto dizi " + file_name(obj)+ZJSEP;
	}

	

	//	if(obj->query("ridable"))
	//	{
	//		str += "����:ride " + obj->query("id")+ZJSEP;
	//	}
	if(obj->query("race")=="����")
	{
		str += NOR"����:give " + obj->query("id")+ZJSEP;
	}

	if (sizeof(obj->query_skills()) )
	{
		str += "�鿴����:skills " + obj->query("id")+ZJSEP;
	}
	if(obj->query("family") && !userp(obj))
	{
		str += "��ʦ:bai " + obj->query("id")+ZJSEP;
	}

	if(obj->is_quester())
	{
		str += "��ȡ����:quest " + obj->query("id")+ZJSEP;
	}
	if (obj->query("id")==me->query("quest/master_id"))
	{
		str += "���׼�:give head to "+ obj->query("id")+ZJSEP;
		str += "ȡ������:quest cancel"+ZJSEP;
	}

	if(userp(obj))
	{
		str += "����:vote chblk " + file_name(obj)+ZJSEP;
		str += "���:team with " + file_name(obj)+ZJSEP;
		str += HIC"˽��"NOR":bei2 " + obj->query("id")+ZJSEP;
	}
	if(me->query("family/family_name")=="����"&&me->query_skill_mapped("force") == "biyun-xinfa")
	str += HIC"��������"NOR":exert force.jiedu " + file_name(obj)+ZJSEP;
	else
	str += HIC"�ⶾ"NOR":exert dispel " + file_name(obj)+ZJSEP;

	if((me->query("family/family_name")=="ŷ������"&&me->query_skill_mapped("force") == "hamagong")||(me->query("family/family_name")=="������"&&me->query_skill_mapped("force") == "huagong-dafa"))
	str += HIC"���䶾ҩ"NOR":exert force.tan " + file_name(obj)+ZJSEP;

	str += "����:follow " + obj->query("id")+ZJSEP;
	if(userp(obj))
	{
		str += "�鿴װ��:arm " + obj->query("id")+ZJSEP;
		str += "��Ӻ���:friend -add " + obj->query("id")+ZJSEP;

	}

	if(obj->is_character())
	{
		str += HIR"����"NOR":steal " + obj->query("id")+ZJSEP;
	}
	if(obj && !environment(obj)->query("no_fight"))
	{
		str += HIR"�����д�"NOR":fight " + obj->query("id")+ZJSEP;
		str += RED"ͻȻϮ��"NOR":touxi " + obj->query("id")+ZJSEP;
		str += RED"��������"NOR":kill " + obj->query("id")+ZJSEP;
		str += HIM"���޹���"NOR":attack " + obj->query("id")+ZJSEP;
	}
	if( wizardp(me)) 
	{ 
		str += "������ɱ:smash " + obj->query("id")+ZJSEP;
		str += "�鿴����:i " + obj->query("id")+ZJSEP;
		str += "�鿴״̬:hp " + obj->query("id")+ZJSEP;
		str += "�鿴�ۺ�:score " + obj->query("id")+ZJSEP;
		str += "�鿴װ��:arm " + obj->query("id")+ZJSEP;
		str += "��������:update " + obj->query("id")+ZJSEP;
		str += "�����书:copyskill " + obj->query("id")+ZJSEP;
		str += HIM"��ʾ����"NOR":data " + obj->query("id")+ZJSEP;
		
	} 
	if(wizardp(me)&&playerp(obj))
	{
		str +=  HIY"�ָ�״̬"NOR":full " + obj->query("id")+ZJSEP; 
		str += "�������:goto " + obj->query("id")+ZJSEP;
		str += "ץ������:summon " + obj->query("id")+ZJSEP;
		
		str += "������Ϣ:snoop " + obj->query("id")+ZJSEP;
		str += "ֹͣ����:snoop none"+ZJSEP;
		
		if(obj->query("chblk_on"))
		str += HIG"�ָ�Ƶ��"NOR":unchblk " + obj->query("id")+ZJSEP;
		else
		str += HIM"�ر�Ƶ��"NOR":chblk " + obj->query("id")+ZJSEP;	
		
		str += "IP��ѯ:sameip " + obj->query("id")+ZJSEP;
		
		str += HIR"�߳���Ϸ"NOR":kickout " + obj->query("id")+ZJSEP;
		str += HIG"��һص�"NOR":huidang " + obj->query("id")+ZJSEP;
		str +=  HIY"��ֵ��ʯ"NOR":paym " + obj->query("id")+ZJSEP; 
		str +=  HIY"��ֵ���"NOR":GMCZtianji " + obj->query("id")+ZJSEP; 

	}
	return str+"\n";
}

int look_living(object me, object obj)
{
	int per;
	int spi;
	int age;
	int weight;
	string str, limb_status, pro, desc;
	mixed *inv;
	mapping my_fam, fam;
	int me_shen, obj_shen;
	obj_shen = (int)obj->query("shen");
	per = obj->query_per();
	age = obj->query("age");
	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	/*
	if (playerp(obj) && ! (obj->query("born")))
	{
		tell_object(me, pro + "��û��Ͷ̥��ֻ��һ��Ԫ��ʲô��������Ү��\n");
		return 1;
	}
*/
	me_shen = (int)me->query("shen");
	if (me != obj)
	{
		if (!wizardp(me)) {
			if (!obj->query("env/no_show")) 
			message("vision", me->name() + "�������´������㡣\n", obj);
			message("vision", me->name() + "�������´�����" + obj->name() + "��\n", environment(me), ({ me, obj }));
		}
	}
	if (wizardp(me) || !userp(obj) || environment(me) == environment(obj))
	str = ZJOBLONG+obj->short()+ZJBR+(!userp(obj) ? obj->long():"")+"\n";
	else
	str = ZJOBLONG+obj->query("title") + " "+obj->name()+"\n";
	//if obj no long
	//	if(obj->query("long")) str += obj->query("long");
	
	if(obj->query("banghui"))
	{
		str += obj->query("banghui/name")+obj->query("banghui/zhiwei")+"\n";
	}
	str += "һһһһһһһһһһһһһһһһһһһһһһһ\n";
	if (me != obj && objectp(obj->query_temp("is_riding")))
	str += sprintf("%s������%s�ϣ���ͷ�����㡣\n", pro, obj->query_temp("is_riding")->name());

	if (obj->is_character() &&
			obj->query("can_speak"))
	{
		// �������ɫ
		if (age >= 25 && obj->query("special_skill/youth"))
		str += pro + "��������͵Ĵ�С������ֻ�ж�ʮ����\n";
		else
		{
			if (age >= 200)
			str += pro + "��������ͺܴ��ˣ����Թ��ơ�\n";
			else
			if (age < 10)
			str += pro + "������������ס�\n";
			else
			str += pro + "��������" + chinese_number(age / 10 * 10) +
			"���ꡣ\n";
		}
		str += sprintf("%s��ʵ������", pro);
		str +=gettof(obj);
		str +=sprintf("��");
		str +=sprintf("�����ƺ�");
		str +=getdam(me,obj);
		str +=sprintf("��\n");
	}

	desc = description(obj);
	if (desc && desc != "")
	str += pro + desc;

	//check about wife and husband
	if (obj->query("id")== me->query("couple/id"))
	{
		// ���޹�ϵ
		if ((string)me->query("gender") == "Ů��")
		str += sprintf("%s������ķ����\n", pro);
		else
		str += sprintf("%s����������ӡ�\n", pro);
	} else
	if (obj->is_brother(me))
	{
		// �ֵ�
		if (obj->query("gender") == "Ů��")
		{
			if (obj->query("mud_age") > me->query("mud_age"))
			str += sprintf("%s�������㡣\n", pro);
			else
			str += sprintf("%s����Ľ������ӡ�\n", pro);
		} else
		{
			if (obj->query("mud_age") > me->query("mud_age"))
			str += sprintf("%s����Ľ����ֳ���\n", pro);
			else
			str += sprintf("%s�������ܡ�\n", pro);
		}
	} else
	if (obj != me && obj->query("league") &&
			obj->query("league/league_name") == me->query("league/league_name"))
	{
		str += sprintf("%s�������%s��ͬ����ʿ��\n", pro,
		obj->query("league/league_name"));
	}

	// If we both has family, check if we have any relations.
	if (obj != me &&
			mapp(fam = obj->query("family")) &&
			mapp(my_fam = me->query("family")) &&
			fam["family_name"] == my_fam["family_name"])
	{

		if (fam["generation"] == my_fam["generation"])
		{

			if ((string)obj->query("gender") == "����" ||
					(string)obj->query("gender") == "����")
			str += sprintf( pro + "�����%s%s��\n",
			my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
			my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
			else
			str += sprintf( pro + "�����%s%s��\n",
			my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
			my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
		} else
		if (fam["generation"] < my_fam["generation"])
		{
			if (my_fam["master_id"] == obj->query("id"))
			str += pro + "�����ʦ����\n";
			else
			if (my_fam["generation"] - fam["generation"] > 1)
			str += pro + "�����ͬ�ų�����\n";
			else
			if (fam["enter_time"] < my_fam["enter_time"])
			str += pro + "�����ʦ����\n";
			else
			str += pro + "�����ʦ�塣\n";
		} else
		{
			if (fam["generation"] - my_fam["generation"] > 1)
			str += pro + "�����ͬ������\n";
			else
			if (fam["master_id"] == me->query("id"))
			str += pro + "����ĵ��ӡ�\n";
			else
			str += pro + "�����ʦֶ��\n";
		}
	}

	if (obj->is_chatter())
	{
		message("vision", str, me);
		return 1;
	}

	if (stringp(obj->query_temp("eff_status_msg")))
	{
		str += obj->query_temp("eff_status_msg") + "\n";
	} else
	if (obj->query("max_qi"))
	str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if (obj->query_temp("daub/poison/remain") &&
			(me == obj || random((int)me->query_skill("poison", 1)) > 80))
	{
		str += pro + HIG "��������" + (me == obj ? "" : "�ƺ�") +
		"����" + (me == obj ? obj->query_temp("daub/poison/name") : "��") +
		NOR "��\n";
	}

	str += look_equiped(me, obj, pro);
	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
	str = str[0..(strlen(str)-5)];
	str += "\n";
	str += desinq(me,obj);
	str += getact(me,obj);
	message("vision", str+"\n", me);

	if (obj != me && living(obj) &&
			! me->is_brother(obj) &&
			me->query("couple/id") != obj->query("id") &&
			(me_shen < -1000 && obj_shen > 1000 ||
				me_shen > 1000  && obj_shen < -1000))
	{
		tell_object(me, obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
		if (obj->query("total_hatred") > 4 * obj->query_skill("force") &&
				! wizardp(obj) && ! wizardp(me))
		COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;
	string str,str1,str2,*strs;
	int i;

	str1 = "";
	str2 = "";
	if (! objectp(env = environment(me)))
	return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
	if (mapp(item = env->query("item_desc")) && !undefinedp(item[arg]))
	{
		if (stringp(item[arg]))
		str = item[arg];
		else if(functionp(item[arg]))
		str = (string)(*item[arg])(me);
		strs = explode(str,"\n");
		for(i=0;i<sizeof(strs);i++)
		{
			if(strlen(strs[i])>4&&(strs[i][0..3]==ZJOBACTS||strs[i][0..3]==ZJOBACTS2))
			str2 += strs[i]+"\n";
			else
			str1 += strs[i]+"\n";
		}
		str = replace_string(str1,"\n",ZJBR);
		if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];
		str += "\n"+str2+"\n";
		tell_object(me, ZJOBLONG+str);

		return 1;
	}
	if (mapp(exits = env->query("exits")) && ! undefinedp(exits[arg]))
	{
		if (objectp(env = find_object(exits[arg])))
		look_room(me, env, 0);
		else
		{
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]), 0);
		}
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

string getdam(object me, object obj)
{

	int level;
	level = obj->query_temp("apply/damage") + obj->query("jiali");
	level = level / 30;
	if( level >= sizeof(heavy_level_desc) )
	level = sizeof(heavy_level_desc)-1;
	return heavy_level_desc[((int)level)];
}
int help(object me)
{
write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]

���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ������
��lookָ������в��������Ȳ쿴�����Ƿ��и���Ʒ�����û�����
�������ڵĻ������Ƿ��и���Ʒ�������������ϵ���Ʒ��������
�Ļ�����ID��ͬ����Ʒ�������ָ��look ??? of me/here ��ָ����
��Ҫ�쿴�Լ����ϵ���Ʒ���Ǹ��������е���Ʒ��ͬʱ�����ʹ����
�� look ??? of <id> ���Կ����˵�װ����������������Ʒ��

HELP
);
	return 1;
}

