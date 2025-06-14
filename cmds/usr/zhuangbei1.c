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

	line += BBLU+" ["+ob->query("name")+"] 的装备属性如下："NOR"\n";
	line += sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
	line += ob->suit(ob);   //套装信息
	line += sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
	if(islook)
	{
		prepare = me->query_skill_prepare();
		if( objectp(weapon = ob->query_temp("weapon")) )
			skill_type = weapon->query("skill_type");
		else if (prepare&&sizeof(prepare)>0)  skill_type = (keys(prepare))[0];
		else
			skill_type = "unarmed";

		attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
		parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
		dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
		line += sprintf("│   战斗攻击： " HIW "%8d  "NOR" 战斗防御： " HIW "%8d "NOR"\n",attack_points /100000  + 1, (dodge_points + (weapon? parry_points: (parry_points/10))) /100000  + 1);
		line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
		line += sprintf("│   兵器伤害： " HIC "%8d  "NOR" 装备防护： "HIC"%8d"NOR"\n", ob->query_temp("apply/damage"),ob->query_temp("apply/armor") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   研究次数： " HIC "%8d  "NOR" 学习次数： "HIC"%8d"NOR"\n", ob->query("research_times"),ob->query("xuexi_times") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   血量上限： " HIC "%8d  "NOR" 精力上限： "HIC"%8d"NOR"\n", ob->query("xueliang"),ob->query("jli") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   削弱绝招： " HIC "%8d  "NOR" 沉默攻击： "HIC"%8d"NOR"\n", ob->query("apply/xuruo_perform"),ob->query("apply/no_perform") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   化解伤害： " HIC "%8d  "NOR" 化解忙乱： "HIC"%8d"NOR"\n", ob->query("reduce_damage"),ob->query("reduce_busy") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   追加伤害： " HIC "%8d  "NOR" 虚弱伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_damage"),ob->query("apply/xuruo_damage") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   战力削弱： " HIC "%8d  "NOR" 绝招防御： "HIC"%8d"NOR"\n", ob->query("apply/xuruo_status"),ob->query("apply/perform_dp") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   追加防御： " HIC "%8d  "NOR" 内息紊乱： "HIC"%8d"NOR"\n", ob->query("apply/add_armor"),ob->query("apply/no_exert") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   忙乱敌人： " HIC "%8d  "NOR" 命中加成： "HIC"%8d"NOR"\n", ob->query("apply/busy_time"),ob->query("apply/attack") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   生命偷取： " HIC "%8d  "NOR" 内力偷取： "HIC"%8d"NOR"\n", ob->query("apply/leech_qi"),ob->query("apply/leech_neili") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   双倍伤害： " HIC "%8d  "NOR" 伤转内力： "HIC"%8d"NOR"\n", ob->query("apply/double_damage"),ob->query("apply/qi_abs_neili") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   穿透护甲： " HIC "%8d  "NOR" 内力恢复： "HIC"%8d"NOR"\n", ob->query("apply/through_armor"),ob->query("apply/neili_recover") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   生命恢复： " HIC "%8d  "NOR" 精气恢复： "HIC"%8d"NOR"\n", ob->query("apply/qi_recover"),ob->query("apply/jing_recover") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   毒之伤害： " HIC "%8d  "NOR" 魔之伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_poison"),ob->query("apply/add_magic") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   金之伤害： " HIC "%8d  "NOR" 木之伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_metal"),ob->query("apply/add_wood") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   水之伤害： " HIC "%8d  "NOR" 火之伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_water"),ob->query("apply/add_fire") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   土之伤害： " HIC "%8d  "NOR" 毒伤抗性： "HIC"%8d"NOR"\n", ob->query("apply/add_earth"),ob->query("apply/reduce_poison") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   魔伤抗性： " HIC "%8d  "NOR" 金伤抗性： "HIC"%8d"NOR"\n", ob->query("apply/reduce_magic"),ob->query("apply/reduce_metal") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   木伤抗性： " HIC "%8d  "NOR" 水伤抗性： "HIC"%8d"NOR"\n", ob->query("apply/reduce_wood"),ob->query("apply/reduce_water") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   火伤抗性： " HIC "%8d  "NOR" 土伤抗性： "HIC"%8d"NOR"\n", ob->query("apply/reduce_fire"),ob->query("apply/reduce_earth") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   忽视毒伤： " HIC "%8d  "NOR" 致盲概率： "HIC"%8d"NOR"\n", ob->query("apply/avoid_poison"),ob->query("apply/add_blind") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   冰冻概率： " HIC "%8d  "NOR" 遗忘概率： "HIC"%8d"NOR"\n", ob->query("apply/add_freeze"),ob->query("apply/add_forget") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   虚弱概率： " HIC "%8d  "NOR" 忙乱概率： "HIC"%8d"NOR"\n", ob->query("apply/add_weak"),ob->query("apply/add_busy") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   忽视致盲： " HIC "%8d  "NOR" 忽视冰冻： "HIC"%8d"NOR"\n", ob->query("apply/avoid_blind"),ob->query("apply/avoid_freeze") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   忽视遗忘： " HIC "%8d  "NOR" 忽视虚弱： "HIC"%8d"NOR"\n", ob->query("apply/avoid_forget"),ob->query("apply/avoid_weak") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   忽视忙乱： " HIC "%8d  "NOR" 化解忙乱： "HIC"%8d"NOR"\n", ob->query("apply/avoid_busy"),ob->query("apply/reduce_busy") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   忽视恐惧： " HIC "%8d  "NOR" 致命一击： "HIC"%8d"NOR"\n", ob->query("apply/avoid_fear"),ob->query("apply/fatal_blow") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   闪电攻击： " HIC "%8d  "NOR" 冷冻攻击： "HIC"%8d"NOR"\n", ob->query("apply/resistance/lighting"),ob->query("apply/resistance/cold") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
line += sprintf("│   火焰攻击： " HIC "%8d  "NOR" 魔法攻击： "HIC"%8d"NOR"\n", ob->query("apply/resistance/fire"),ob->query("apply/resistance/magic") );
line+= sprintf(HIC"≡"BGRN"○○○○○○○○○○○○○○○○○○○○○"BGRN"≡"NOR"\n");
	}
	// 先用无颜色的做排列(如此色码才不会被算进去导致乱掉)
//	if(!arg)
//		tmp += "[穿戴装备]:wear all"ZJSEP"[脱掉装备]:remove all"ZJSEP;
//	    tmp += "[ 召 唤 装 备 ]:summon all"ZJSEP;
//        tmp += "[手持武器]:wield all"ZJSEP"[放下武器]:unwield all"ZJSEP;

//	tmp += sprintf("[右手]：%s[左手]：%s",wp1, wp2);
//	tmp += sprintf("[脸部]：%s[护腕]：%s", name_temp(ob,"armor/face"), name_temp(ob,"armor/wrists"));
//	tmp += sprintf("[颈部]：%s[手部]：%s", name_temp(ob,"armor/neck"), name_temp(ob,"armor/hands"));
//	tmp += sprintf("[衣服]：%s[护甲]：%s",name_temp(ob,"armor/cloth"), name_temp(ob,"armor/armor"));
//	tmp += sprintf("[盾牌]：%s[腰部]：%s", name_temp(ob,"armor/shield"),name_temp(ob,"armor/waist"));
//	tmp += sprintf("[头部]：%s[裤子]：%s",name_temp(ob,"armor/head"), name_temp(ob,"armor/pants"));
//	tmp += sprintf("[戒指]：%s[足部]：%s", name_temp(ob,"armor/finger"), name_temp(ob,"armor/boots"));
	line = replace_string(line,"\n",ZJBR)+"\n";
//	line += tmp;
	write(ZJOBLONG+line+"\n");

	return 1;

}

int help (object me)
{
	write(@HELP
指令格式: arm

可列出你(你)目前身上所携带的所有物品。


HELP );
	return 1;
}