//arm.c

#include <ansi.h>
#include <tomud.h>
#include <combat.h>
inherit F_CLEAN_UP;

string name_temp(object ob,string type);

int main(object me, string arg)
{
	int i;
	object ob;
	mapping prepare;
	int attack_points, dodge_points, parry_points,islook;
	object weapon,second_weapon;
	string line,tmp,wp1,wp2,skill_type;

	if (arg)
	{
		ob = find_player(arg);
		if (! ob) ob = find_living(arg);
		if (! ob) ob = present(arg, environment(me));
		if (! wizardp(me) && (! ob || me->query("couple/child") != ob->query("id")))
		{
		      islook=0;   //不是巫师或孩子不能看具体攻击防御数值
		}
		else
		{
		      islook=1;       //可以查看全部数值
		}
		if(!ob)
		{
		     return notify_fail("你要察看谁的装备？\n");
		}
	}
	if (! ob)
	{
		ob = me;
	      islook=1;       //可以查看全部数值
	}
	if( ob==me && me->is_ghost() )
		return notify_fail("这些身外之物，生不带来，死不带去，还是算了吧！\n");

	line="";
	tmp=ZJOBACTS2+ZJMENUF(2,2,10,30);
	wp1="无:null"ZJSEP;
	wp2="无:null"ZJSEP;

	weapon= ob->query_temp("weapon");
	second_weapon= ob->query_temp("secondary_weapon");
	if(weapon)
	{
		wp1=weapon->query("name")+":look "+weapon->query("id")+ZJSEP;
	}
	if(second_weapon)
	{
		  wp2=second_weapon->query("name")+":look "+weapon->query("id");
	}

	line += BBLU+" ["+ob->query("name")+"] 的穿戴装备如下："NOR"\n";
	line += sprintf(HIY"一一一一一一一一一一一一一一一一一一一一一一一"NOR"\n");
	line += ob->suit(ob);   //套装信息
	line += sprintf(HIY"一一一一一一一一一一一一一一一一一一一一一一一"NOR"\n");
	if(islook)
	{
		prepare = me->query_skill_prepare();
		if( objectp(weapon = ob->query_temp("weapon")) )
			skill_type = weapon->query("skill_type");
		else if (prepare&&sizeof(prepare)>0)  skill_type = (keys(prepare))[0];
		else
			skill_type = "unarmed";

//		attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
//		parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
//		dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
//		line += sprintf("│   战斗攻击力： " HIW "%8d  "NOR" 战斗防御力： " HIW "%8d "NOR"\n",
//		attack_points  + 1, (dodge_points + (weapon? parry_points: (parry_points/10)))  + 1);
//		line += sprintf("│   兵器伤害： " HIC "%8d  "NOR" 装备防护： "HIC"%8d"NOR"\n", ob->query_temp("apply/damage"),ob->query_temp("apply/armor") );
//		line += sprintf("│   暴击增加： " HIC "%8d  "NOR" 抗暴增加： "HIC"%8d"NOR"\n", ob->query_temp("apply/2ap"),ob->query_temp("apply/2dp") );
//		line += sprintf("│   护甲增加： " HIC "%8d  "NOR" 破甲增加： "HIC"%8d"NOR"\n", ob->query_temp("apply/armor"),ob->query_temp("apply/break") );
//		line += sprintf("│   削弱绝招： " HIC "%8d  "NOR" 沉默攻击： "HIC"%8d"NOR"\n", ob->query("apply/xuruo_perform"),ob->query("apply/no_perform") );
//		line += sprintf("│   化解伤害： " HIC "%8d  "NOR" 化解忙乱： "HIC"%8d"NOR"\n", ob->query("apply/reduce_damage"),ob->query("apply/reduce_busy") );
//		line += sprintf("│   追加伤害： " HIC "%8d  "NOR" 虚弱伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_damage"),ob->query("apply/xuruo_damage") );
//		line += sprintf("│   战力削弱： " HIC "%8d  "NOR" 绝招防御： "HIC"%8d"NOR"\n", ob->query("apply/xuruo_status"),ob->query("apply/perform_dp") );
//		line += sprintf("│   追加防御： " HIC "%8d  "NOR" 内息紊乱： "HIC"%8d"NOR"\n", ob->query("apply/add_armor"),ob->query("apply/no_exert") );
//		line += sprintf("│   忙乱敌人： " HIC "%8d  "NOR" 命中加成： "HIC"%8d"NOR"\n", ob->query("apply/busy_time"),ob->query("apply/attack") );
//		line += sprintf("│   研究次数： " HIC "%8d  "NOR" 练习次数： "HIC"%8d"NOR"\n", ob->query("apply/research_times"),ob->query("apply/practice_times") );
//		line += sprintf("│   血量上限： " HIC "%8d  "NOR" 精力上限： "HIC"%8d"NOR"\n", ob->query("apply/xueliang"),ob->query("apply/jli") );
//		line+= sprintf(HIY"一一一一一一一一一一一一一一一一一一一一一一一"NOR);
	}
	// 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
	if(!arg)
		tmp += "[穿戴装备]:wear all"ZJSEP"[脱掉装备]:remove all"ZJSEP;
	    tmp += "[ 召 唤 装 备 ]:summon all"ZJSEP;
//        tmp += "[手持武器]:wield all"ZJSEP"[放下武器]:unwield all"ZJSEP;

	tmp += sprintf("[右手]：%s[左手]：%s",wp1, wp2);
	tmp += sprintf("[脸部]：%s[护腕]：%s", name_temp(ob,"armor/face"), name_temp(ob,"armor/wrists"));
	tmp += sprintf("[颈部]：%s[手部]：%s", name_temp(ob,"armor/neck"), name_temp(ob,"armor/hands"));
	tmp += sprintf("[衣服]：%s[护甲]：%s",name_temp(ob,"armor/cloth"), name_temp(ob,"armor/armor"));
	tmp += sprintf("[盾牌]：%s[腰部]：%s", name_temp(ob,"armor/shield"),name_temp(ob,"armor/waist"));
	tmp += sprintf("[头部]：%s[裤子]：%s",name_temp(ob,"armor/head"), name_temp(ob,"armor/pants"));
	tmp += sprintf("[戒指]：%s[足部]：%s", name_temp(ob,"armor/finger"), name_temp(ob,"armor/boots"));
	line = replace_string(line,"\n",ZJBR)+"\n";
	line += tmp;
	write(ZJOBLONG+line+"\n");

	return 1;
}
string name_temp(object ob,string type)
{
	string name;
	object obj;
	if( objectp(obj=ob->query_temp(type)) )
	{
		name = obj->query("name")+":"+obj->query("id")+ZJSEP;
	}
	else
	{
		name = "无:null"ZJSEP;
	}
	return name;
}

int help (object me)
{
	write(@HELP
指令格式: arm

可列出你(你)目前身上所携带的所有物品。


HELP );
	return 1;
}