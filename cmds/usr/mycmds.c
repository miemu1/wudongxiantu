// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i,bt;
	string str,cmd;

	if(!arg)
	{
		write(ZJBTSET"b12:常用"HIG""ZJBR"功能"NOR":mycmds ofen"ZJSEP"b13:基础"HIY""ZJBR"技能"NOR":mycmds skill"ZJSEP"b14:战斗"HIR""ZJBR"快捷"NOR":mycmds fight"ZJSEP
			"b15:玩法"HIM""ZJBR"功能"NOR":mycmds quest"ZJSEP"b16:功能"HIW""ZJBR"玩法"NOR":mycmds help"ZJSEP"b17:聊天"HIC""ZJBR"系统"NOR":liaotian"+"\n");
		write(ZJTTMENU HIW"在线奖励 :getreward -online"ZJSEP"幸运抽奖 :luckdraw"ZJSEP"返回客栈 :recall ce"ZJSEP"返回师门 :recalle back\n"NOR);
	}
	else if(arg=="ofen")
		write(ZJBTSET"b1:个人"ZJBR"信息:help gerxinx"ZJSEP"b2:健康"ZJBR"状态:hp"ZJSEP"b3:背包"ZJBR"道具:i"
	          ZJSEP"b4:武器"ZJBR"装备:help zbgrxx"ZJSEP"b5:兑换"ZJBR"系统:help duihuanxt"ZJSEP"b6:商城"ZJBR"购物:help shangcheng"ZJSEP"b8:奇经"ZJBR"八脉:beat"
			  ZJSEP"b7:等级"ZJBR""NOR"系统:uplv -h"ZJSEP"b9:队伍"ZJBR""NOR"详细:team"ZJSEP"b10:称号"ZJBR""NOR"系统:help chenhaoxt"ZJSEP"b11:游戏"ZJBR""NOR"排行:tops"+"\n");
	else if(arg=="skill")
		write(ZJBTSET"b1:查看"ZJBR"技能:skills"ZJSEP"b2:练功"ZJBR"系统:help liangong"ZJSEP"b3:战斗"ZJBR"显示:set combatd"
			ZJSEP"b4:天赋"ZJBR"技能:special"ZJSEP"b5:逃跑"ZJBR"系数:wimpy"ZJSEP"b6:恢复"ZJBR"精神:exert inspire"
			ZJSEP"b7:治疗"ZJBR"疾病:exert dispel"ZJSEP"b8:内力"ZJBR"伤敌:enforce"ZJSEP"b9:恢复"ZJBR"血量:exert recover"ZJSEP"b10:恢复"ZJBR"精力:exert regenerate"ZJSEP"b11:治疗"ZJBR"伤势:exert heal"+"\n");
	else if(arg=="fight")
	{
		str = ZJBTSET;
		for(i=1;i<11;i++)
		{
			if(cmd=me->query("mycmds/fight/b"+i))
				str += "b"+i+":"+cmd;
			else
				str += "b"+i+":点击"ZJBR"选择"+i+":mycmds reset "+i;
			str += ZJSEP;
		}
		str += "b11:重新"ZJBR"定义:mycmds reset";
		write(str+"\n");
	}
	else if(arg=="quest")
		write(ZJBTSET"b1:任务"ZJBR"功能:help rengwugn"ZJSEP"b2:战令"ZJBR"系统:zhanling"ZJSEP"b3:推荐"ZJBR"副本:flygo"
			  ZJSEP"b4:休闲"ZJBR"功能:life"ZJSEP"b5:宠物"ZJBR"系统:pet"ZJSEP"b7:"HIR"肉身"ZJBR"修炼"NOR":tupo explain"ZJSEP"b8:"HIR"帮会"ZJBR"系统"NOR":banghui"
			  ZJSEP"b6:好友"ZJBR"系统:help hyjy"ZJSEP"b9:推广"ZJBR"系统:tg"ZJSEP"b10:修仙"ZJBR"系统:xiulians1"ZJSEP"b11:铠甲"ZJBR"系统:kaijia"+"\n");
	else if(arg=="help")
		write(ZJBTSET"b1:战魂"ZJBR"系统:zhanhun"ZJSEP"b2:暂"ZJBR"无"NOR":暂无"ZJSEP"b3:暂"ZJBR"无:暂无"ZJSEP"b4:保存"ZJBR"存档:save"
			  ZJSEP"b5:游戏"ZJBR"设置:set nocha_skills"ZJSEP"b6:删档"ZJBR"重开:suicide"ZJSEP"b7:推荐"ZJBR"功法:help skills"ZJSEP"b8:新手"ZJBR"指南:help newbie"
			  ZJSEP"b9:基本"ZJBR"系统:help"ZJSEP"b10:货币"ZJBR"说明:help pay"ZJSEP"b11:"YEL"门派"ZJBR"世家"NOR":help menpai"+"\n");
	else if(arg=="reset")
	{
		str = ZJBTSET;
		for(i=1;i<11;i++)
		{
			str += "b"+i+":点击"ZJBR"选择"+i+":mycmds reset "+i;
			str += ZJSEP;
		}
		str += "b11:返回:mycmds fight";
		write(str+"\n");
		write(ZJTMPSAY"请点击你想要定义的按钮选择新功能。\n");
	}
	else if(sscanf(arg,"reset %d %s",bt,cmd)==2)
	{
		string a,b;

		if(bt<1||bt>10)
			return notify_fail(ZJOBLONG"没有这个按钮。。。\n");
		if(cmd == "自定义")
		{
			write(INPUTTXT("请输入自定义字串：标题:命令(查看:look)","mycmds reset "+bt+" $txt#")+"\n");
			return 1;
		}
		cmd = replace_string(cmd,"：",":");
		cmd = replace_string(cmd,"#E",ESA);
		cmd = replace_string(cmd,"/",ZJBR);
		cmd = replace_string(cmd,"\n",ZJBR);
		if(sscanf(cmd,"%s:%s",a,b)!=2)
			return notify_fail(HIR"格式错误，请重新定义！"NOR"\n");
		me->set("mycmds/fight/b"+bt,cmd);
		write(ZJBTSET"b"+bt+":"+cmd+"\n");
	}
	else if(sscanf(arg,"reset %d",bt)==1)
	{
		mapping smap, pmap, pfms,skips;
		string force_ski,weapon_ski,*pfm,ski_type,uski_type;
		int k,flag;
		string msg,*valid_types,*skis,*cmdd;
		object weapon;

		if(bt<1||bt>10)
			return notify_fail(ZJOBLONG"没有这个按钮。。。\n");

		valid_types = ({"finger","hand","cuff","claw","strike","unarmed","spells"});
		skips = ([]);
		if(!smap = me->query_skill_map()) smap=([]);
		if(!pmap = me->query_skill_prepare()) pmap=([]);
		msg = "";

		if(objectp(weapon = me->query_temp("weapon")))
			ski_type = weapon->query("skill_type");

		if(force_ski=smap["force"])
		{
			pfms = SKILL_D(force_ski)->query_pfm("force");
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":mycmds reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" force."+pfm[i]+ZJSEP;
					skips[force_ski+pfm[i]]=1;
				}
			}
		}

		if(force_ski=smap["xinfa"])
		{
			pfms = SKILL_D(force_ski)->query_pfm("xinfa");
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					if(skips[force_ski+pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":mycmds reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" xinfa."+pfm[i]+ZJSEP;
					skips[force_ski+pfm[i]]=1;
				}
			}
		}

		if(force_ski=smap["parry"])
		{
			pfms = SKILL_D(force_ski)->query_pfm("parry");
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					if(skips[force_ski+pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":mycmds reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" parry."+pfm[i]+ZJSEP;
					skips[force_ski+pfm[i]]=1;
				}
			}
		}

		if(force_ski=smap["dodge"])
		{
			pfms = SKILL_D(force_ski)->query_pfm("dodge");
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					if(skips[force_ski+pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":mycmds reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" dodge."+pfm[i]+ZJSEP;
					skips[force_ski+pfm[i]]=1;
				}
			}
		}

		if(objectp(weapon))
		{
			if(stringp(weapon_ski=smap[ski_type]))
			{
				pfms = SKILL_D(weapon_ski)->query_pfm(ski_type);
				if(mapp(pfms)&&pfms!=([]))
				{
					pfm = sort_array(keys(pfms), (: strcmp :) );
					for(i=0;i<sizeof(pfm);i++)
					{
						if(skips[weapon_ski+pfm[i]]) continue;
						cmdd = explode(pfms[pfm[i]],":");
						msg += cmdd[0] + ":mycmds reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" "+ski_type+"."+pfm[i]+ZJSEP;
						skips[weapon_ski+pfm[i]] = 1;
					}
				}
			}
		}
		else if(!objectp(weapon))
		{
			if(mapp(pmap)&&pmap!=([]))
			{//首先推送准备技能
				skis = sort_array(keys(pmap), (: strcmp :) );
				for(k=0;k<sizeof(skis);k++)
				{
					if(skips[pmap[skis[k]]]) continue;
					pfms = SKILL_D(pmap[skis[k]])->query_pfm(skis[k]);
					if(mapp(pfms)&&pfms!=([]))
					{
						pfm = sort_array(keys(pfms), (: strcmp :) );
						for(i=0;i<sizeof(pfm);i++)
						{
							if(skips[pmap[skis[k]]+pfm[i]]) continue;
							cmdd = explode(pfms[pfm[i]],":");
							msg += cmdd[0] + ":mycmds reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" "+skis[k]+"."+pfm[i]+ZJSEP;
							skips[pmap[skis[k]]+pfm[i]] = 1;
						}
					}
				}
			}

			skis = sort_array(keys(smap), (: strcmp :) );
			for(k=0;k<sizeof(skis);k++)
			{
				flag = 1;
				for(i=0;i<sizeof(valid_types);i++)
				{
					if(SKILL_D(smap[skis[k]])->valid_enable(valid_types[i]))
					{
						uski_type = valid_types[i];
						flag = 2;
					}
				}
				if(!skips[smap[skis[k]]]&&flag==2)
				{
					pfms = SKILL_D(smap[skis[k]])->query_pfm(uski_type);
					if(mapp(pfms)&&pfms!=([]))
					{
						pfm = sort_array(keys(pfms), (: strcmp :) );
						for(i=0;i<sizeof(pfm);i++)
						{
							if(skips[smap[skis[k]]+pfm[i]]) continue;
							cmdd = explode(pfms[pfm[i]],":");
							msg += cmdd[0] + ":mycmds reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" "+skis[k]+"."+pfm[i]+ZJSEP;
							skips[smap[skis[k]]+pfm[i]] = 1;
						}
					}
				}
			}
		}
		write(ZJOBLONG"你想设定按钮"HIG+chinese_number(bt)+NOR"为什么功能？\n"ZJOBACTS2+ZJMENUF(5,5,8,30)
			+msg
			+"拉弓"ZJBR"射箭:mycmds reset "+bt+" 拉弓"ZJBR"射箭：shot"ZJSEP
			+"内力"ZJBR"回气:mycmds reset "+bt+" 内力"ZJBR"回气：exert recover"ZJSEP
			+"内力"ZJBR"回精:mycmds reset "+bt+" 内力"ZJBR"回精：exert regenerate"ZJSEP
		    +"内力"ZJBR"疗伤:mycmds reset "+bt+" 内力"ZJBR"疗伤：exert heal"ZJSEP
			+"内力"ZJBR"疗疾:mycmds reset "+bt+" 内力"ZJBR"疗疾：exert dispel"ZJSEP
			+"释放"ZJBR"怒气:mycmds reset "+bt+" 释放"ZJBR"怒气：burning"ZJSEP
			+"吃护"ZJBR"心丹:mycmds reset "+bt+" 吃护"ZJBR"心丹：use huxin dan"ZJSEP
			+"绝技"ZJBR"一:mycmds reset "+bt+" 绝技"ZJBR"一：aa"ZJSEP
			+"绝技"ZJBR"二:mycmds reset "+bt+" 绝技"ZJBR"二：bb"ZJSEP
			+"绝技"ZJBR"三:mycmds reset "+bt+" 绝技"ZJBR"三：cc"ZJSEP
			+"\n");
	}
	return 1;
}

int help(object me)
{
     write(@HELP

这个指令让设定游戏默认的自定义按钮。

HELP
    );
    return 1;
}
