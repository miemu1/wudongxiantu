// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	    object obj,ob,obj1,obj2,obj3,obj4;
        int count,mengxin;
        string a;
		me = this_player();
	if(!arg)
	{
		str = ZJOBLONG"佩戴称号请前往称号界面：\n";
		str += ZJOBACTS2+ZJMENUF(1,1,9,29);
//		str += HIW"萌新礼包码"NOR":jihuo1"ZJSEP""HIG"中秋节礼包"NOR":jihuo2";
	str += WHT"[武者]"NOR"["+((me->query("titles/武者"))?HIG"已激活"NOR:HIR"未激活"NOR)+"]["+((me->query("title")=="武者")?HIG"已佩戴"NOR:HIR"未佩戴"NOR)+"]+ZJBR+["+((me->query("titles/武者"))?HIG"已激活"NOR:HIR"未激活"NOR)+"]:chengh 武者"ZJSEP;
//	str += WHT"[中秋节礼包]"NOR"["+((me->query("jihuom/s2")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo2"ZJSEP;

	}
	

	message("vision", str+"\n", me);

			if(me->is_fighting())
	{
		tell_object(me,"请先脱离战斗。\n");
		return 1;
	}
		if(me->is_busy())
	{
		tell_object(me,"你正忙。\n");
		return 1;
	}
	switch (arg) {
	  case "武者" :
			if(!me->query("titles/武者")&&me->query_skill("force")>=200)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",200);
			me->set("titles/武者",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "1" :
	  {
		str = ZJOBLONG"佩戴称号请前往称号界面：\n";
		str += ZJOBACTS2+ZJMENUF(1,1,7,31);
//		str += HIW"萌新礼包码"NOR":jihuo1"ZJSEP""HIG"中秋节礼包"NOR":jihuo2";
	str += HIC"[武者]"NOR"["+((me->query("titles/武者"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="武者")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																							 "WHT"激活要求："HIR"基本内功>200"NOR"																				  	"WHT"奖励："CYN"先天四维+1，气血+200"NOR":chengh 武者"ZJSEP;
	str += HIC"[毒仙]"NOR"["+((me->query("titles/毒仙"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="毒仙")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																							 "WHT"激活要求："HIR"冰蚕寒功>500"NOR"																					  "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 毒仙"ZJSEP;
	str += HIC"[剑魔]"NOR"["+((me->query("titles/剑魔"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="剑魔")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																							 "WHT"激活要求："HIR"独孤九剑>500"NOR"																					  "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 剑魔"ZJSEP;
	str += HIC"[太极]"NOR"["+((me->query("titles/太极"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="太极")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																						   "WHT"激活要求："HIR"太极(神功、剑法、拳)>500"NOR"								                "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 太极"ZJSEP;
	str += HIC"[阳圣]"NOR"["+((me->query("titles/阳圣"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="阳圣")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																						   "WHT"激活要求："HIR"乾坤大挪移、九阳神功>500"NOR"												"WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 阳圣"ZJSEP;
	str += HIC"[金身]"NOR"["+((me->query("titles/金身"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="金身")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																						   "WHT"激活要求："HIR"金刚不坏体、禅宗心法>500"NOR"												"WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 金身"ZJSEP;
	str += HIC"[佳人]"NOR"["+((me->query("titles/佳人"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="佳人")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																						   "WHT"激活要求："HIR"明玉功、移花接木>500"NOR"								                                            "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 佳人"ZJSEP;
	str += HIC"[君子]"NOR"["+((me->query("titles/君子"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="君子")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																							 "WHT"激活要求："HIR"读书写字>500"NOR"															                        "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 君子"ZJSEP;
	str += HIC"[北冥潇]"NOR"["+((me->query("titles/北冥潇"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="北冥潇")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																						 "WHT"激活要求："HIR"凌波微步、北冥神功>500"NOR"									                                        "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 北冥潇"ZJSEP;
	str += HIC"[南慕容]"NOR"["+((me->query("titles/南慕容"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="南慕容")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																						 "WHT"激活要求："HIR"斗转星移>500"NOR"															                        "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 南慕容"ZJSEP;
	str += HIC"[侠客行]"NOR"["+((me->query("titles/侠客行"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="侠客行")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																						 "WHT"激活要求："HIR"太玄功>500"NOR"															                          "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 侠客行"ZJSEP;
	str += HIC"[暗夜鬼魅]"NOR"["+((me->query("titles/暗夜鬼魅"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="暗夜鬼魅")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"辟邪剑法>500"NOR"															                        "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 暗夜鬼魅"ZJSEP;
	str += HIC"[碧海潮生]"NOR"["+((me->query("titles/碧海潮生"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="碧海潮生")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"碧波神功、碧海潮生曲>500"NOR"					                            "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 碧海潮生"ZJSEP;
	str += HIC"[龙象之力]"NOR"["+((me->query("titles/龙象之力"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="龙象之力")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"龙象般若功>500"NOR"													                         "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 龙象之力"ZJSEP;
	str += HIC"[雪上飞狐]"NOR"["+((me->query("titles/雪上飞狐"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="雪上飞狐")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"冷月神功、胡家刀法>500"NOR"												  "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 雪上飞狐"ZJSEP;
	str += HIC"[如影随行]"NOR"["+((me->query("titles/如影随行"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="如影随行")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"葵花神功、飘渺身法>500"NOR"												  "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 如影随行"ZJSEP;
	str += HIC"[富可敌国]"NOR"["+((me->query("titles/富可敌国"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="富可敌国")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"灵石数量>9999999"NOR"											                                "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 富可敌国"ZJSEP;
	str += HIC"[倾国倾城]"NOR"["+((me->query("titles/倾国倾城"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="倾国倾城")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"女性容貌>50"NOR"											                                "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 倾国倾城"ZJSEP;
	str += HIC"[陌上君子]"NOR"["+((me->query("titles/陌上君子"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="陌上君子")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"男性容貌>50"NOR"											                                "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 陌上君子"ZJSEP;
	str += HIC"[独步江湖]"NOR"["+((me->query("titles/独步江湖"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="独步江湖")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"武学修养、剑道修养>500"NOR"											                                "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 独步江湖"ZJSEP;
	str += HIC"[百岁老人]"NOR"["+((me->query("titles/百岁老人"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="百岁老人")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"人物年龄>100"NOR"											                                "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 百岁老人"ZJSEP;
	str += HIC"[一剑西来]"NOR"["+((me->query("titles/一剑西来"))?WHT"已激活"NOR:WHT"未激活"NOR)+"]["+((me->query("title")=="一剑西来")?HIG"已佩戴"NOR:WHT"未佩戴"NOR)+"]																				 "WHT"激活要求："HIR"飞仙剑法>500"NOR"															                        "WHT"奖励："CYN"先天四维+1，气血+1000"NOR":chengh 一剑西来"ZJSEP;



	message("vision", str+"\n", me);
				return 1;
			}
		break;
	  case "毒仙" :
			if(!me->query("titles/毒仙")&&me->query_skill("freezing-force")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/毒仙",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "剑魔" :
			if(!me->query("titles/剑魔")&&me->query_skill("lonely-sword")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/剑魔",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "太极" :
			if(!me->query("titles/太极")&&me->query_skill("taiji-shengong")>=500&&me->query_skill("taiji-jian")>=500&&me->query_skill("taiji-quan")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/太极",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "阳圣" :
			if(!me->query("titles/阳圣")&&me->query_skill("qiankun-danuoyi")>=500&&me->query_skill("jiuyang-shengong")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/阳圣",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "金身" :
			if(!me->query("titles/金身")&&me->query_skill("jingang-buhuaiti")>=500&&me->query_skill("buddhism")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/金身",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "君子" :
			if(!me->query("titles/君子")&&me->query_skill("literate")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/君子",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "佳人" :
			if(!me->query("titles/佳人")&&me->query_skill("mingyu-gong")>=500&&me->query_skill("yihua-jiemu")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/佳人",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "北冥潇" :
			if(!me->query("titles/北冥潇")&&me->query_skill("beiming-shengong")>=500&&me->query_skill("lingbo-weibu")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/北冥潇",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "南慕容" :
			if(!me->query("titles/南慕容")&&me->query_skill("douzhuan-xingyi")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/南慕容",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "侠客行" :
			if(!me->query("titles/侠客行")&&me->query_skill("taixuan-gong")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/侠客行",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "暗夜鬼魅" :
			if(!me->query("titles/暗夜鬼魅")&&me->query_skill("pixie-jian")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/暗夜鬼魅",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "碧海潮生" :
			if(!me->query("titles/碧海潮生")&&me->query_skill("bibo-shengong")>=500&&me->query_skill("bihai-chaosheng")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/碧海潮生",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "龙象之力" :
			if(!me->query("titles/龙象之力")&&me->query_skill("longxiang")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/龙象之力",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "雪上飞狐" :
			if(!me->query("titles/雪上飞狐")&&me->query_skill("hujia-daofa")>=500&&me->query_skill("lengyue-shengong")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/雪上飞狐",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "如影随行" :
			if(!me->query("titles/如影随行")&&me->query_skill("kuihua-shengong")>=500&&me->query_skill("piaomiao-shenfa")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/如影随行",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	case "富可敌国" :
			if(!me->query("titles/富可敌国")&&me->query("yuanbao")>=9999999)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/富可敌国",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	case "倾国倾城" :
			if(!me->query("titles/倾国倾城")&&me->query("per")>=50&&me->query("gender") == "女性")
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/倾国倾城",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
			case "陌上君子" :
			if(!me->query("titles/陌上君子")&&me->query("per")>=50&&me->query("gender") == "男性")
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/陌上君子",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
					case "独步江湖" :
			if(!me->query("titles/独步江湖")&&me->query_skill("martial-cognize")>=500&&me->query_skill("sword-cognize")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/独步江湖",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
					case "百岁老人" :
			if(!me->query("titles/百岁老人")&&me->query("age")>=100)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/百岁老人",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  case "一剑西来" :
			if(!me->query("titles/一剑西来")&&me->query_skill("feixian-sword")>=500)
			{
			me->add("int",1);
			me->add("dex",1);
			me->add("con",1);
			me->add("str",1);
			me->add("max_qi",1000);
			me->set("titles/一剑西来",1);
//				me->set("zhanlinglq/s1",1);
				tell_object(me,"称号领取成功。\n");
				return 1;
			}else
	{message_vision(HIG"你还没有达到成就领取要求、或者你已经领取过了。"NOR"\n", me);
	    return 1;}
		break;
	  default :
		message_vision(HIC "领取错误，请联系巫师。\n" NOR,me);
	    return 1;
	}		
//              sscanf(arg, "%s ", a);


//        return 1;
	}



int help(object me)
{
     write(@HELP
指令格式: uplv [-s]

这个指令让你消耗修为提升等级。

HELP
    );
    return 1;
}
