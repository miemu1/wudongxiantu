// arg.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object where = environment(me);
	int cishu;
	int shengyu;//剩余师门次数
    int GMT = time() + localtime(0)[8];
	string d, times;
	int h, s;
    int jiacheng,fanbei;
	int suanfa;
	 shengyu=(10000-me->query("shimen/today"));//剩余次数为

	jiacheng=me->query_temp("shimenjiacheng");
	fanbei=me->query_temp("shimenfanbei");
	times = ctime(GMT);
	//Sun(星期日) Mon(星期一)  Tue(星期二)  Wed(星期三)  Thu(星期四)  Fri(星期五)  Sat(星期六)
	d = times[0..2];//星期
	h = to_int(times[10..12]);//时
	s = to_int(times[14..15]);//分


	jiacheng = 1;
	fanbei = 1;

	if (arg=="xianshi")
	{
		
		string msg;
		msg  = ZJOBLONG;
		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");

		msg= ZJOBLONG+HIR "◎"HIY "师门扫荡系统" HIR "◎"NOR+ZJBR;
		msg+=HIG"——————————————————————"NOR+ZJBR;
		msg+=HIW"师门扫荡共计10000次，你还能扫荡"+shengyu+"次\n"NOR;
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "一键扫荡:saodang yijian"ZJSEP;
	//	msg += "刷新扫荡:saodang shuaxin"ZJSEP;
		msg += "选择扫荡:saodang\n";
		message("vision", msg, me);
	}

	if (arg=="shuaxin")//刷新
	{
  
		if (!(d == "Sun")) 
			return notify_fail("你的扫荡只能在星期天刷新。\n");

		me->set("saodang",0);
		me->set("xianzhi",0);
	
		return  notify_fail("刷新成功。\n");
	}	
	if (arg=="ce")
	{
		notify_fail("举起右手在面前极速画了一个圆，大喊"
			"一声，“，铠化！”\n");
		return notify_fail("举起右手在面前极速画了一个圆，大喊"
			"一声，“，铠化！”\n");
	}
	if (arg=="yijian")//一键扫荡
	{
		if(me->query("combat_exp") < 2000000)
			return notify_fail("修为需要200万才能开始扫荡。\n");
		if(me->query("xianzhi")==1)
			return notify_fail("你已经扫荡过了。\n");
   		if (me->is_busy())
			return notify_fail("你现在正忙着呢。\n");
		if (environment(me)->query("no_learn") || environment(me)->query("no_fight") && (me->query("doing") != "scheme" || this_player(1)))
			return notify_fail("这里太纷杂，你没法作扫荡。\n"); 
		if (me->is_fighting())
			return notify_fail("临阵磨枪？来不及啦。\n");
		if (me->query("saodang")>=1)
			return notify_fail("你已经用过选择扫荡了。\n");
		
		if (me->query("shimen/today")>=10000)
		{
			return notify_fail("你的扫荡此时已经用完啦。\n");
		}
		
       
		suanfa=shengyu*fanbei;
		me->add("shimen/today",shengyu);
		me->add("combat_exp",(1000+jiacheng)*suanfa);//修为
		me->add("potential",(1000+jiacheng)*suanfa);//潜能
	    me->add("experience", (25+jiacheng)*suanfa);//体会
		if(me->query("shen")>0)
		{
	    me->add("shen", (10+jiacheng)*suanfa);//正神
		}
	    else
		{
		me->add("shen", -(10+jiacheng)*suanfa);//正神
		}
	    me->add("score", (10+jiacheng)*suanfa);//阅历
		me->add("xianzhi",1);
		me->add("jifeng",(3+jiacheng)*suanfa);
	    me->add("weiwang", (10+jiacheng)*suanfa);//威望		
        me->start_busy(5);		
		tell_object(me, HIW"扫荡成功。你一共扫荡了"+shengyu+"次\n，获得"+(3+jiacheng)*suanfa+"点券\n"+(1000+jiacheng)*suanfa+"修为\n"+(1000+jiacheng)*suanfa+"潜能\n"+(25+jiacheng)*suanfa+"体会\n"+(10+jiacheng)*suanfa+"正神\n"+(10+jiacheng)*suanfa+"阅历\n"+(10+jiacheng)*suanfa+"威望\n"NOR);
		
		return  1;

		//if ((time() / 86400 - me->query("arg_last_time") / 86400)<=7)//时间为七天一循环
		//	return notify_fail("还没有到七天哦。无法继续扫荡\n");
		return  notify_fail("扫荡成功。\n");
	}
	
	if (!arg || arg == "")
	{
		if (!me->query("tingyvge"))
		{
			return notify_fail("你不是天下最好看的人所以你无法使用.\n");
		}
		write(INPUTTXT("输入次数", "saodang $txt#") + "\n");//增加扫荡的次数
		return 0;
	}

	//if (sscanf(arg, "%d", cishu) == 1)//读取arg为数字 则赋值cishu 返回值为1
	if (sscanf(arg, "%d", cishu) != 1) return 1;//如果不等于就直接返回

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (environment(me)->query("no_learn") || environment(me)->query("no_fight") && (me->query("doing") != "scheme" || this_player(1)))
		return notify_fail("这里太纷杂，你没法作扫荡。\n"); 

	if (cishu < 1 || cishu > 1000)
		return notify_fail("扫荡次数最少一次，最多也不能超过1000次。\n");

	if (shengyu>cishu)
	return notify_fail("扫荡次数不能大于师门剩余次数\n");
	if (me->query("shimen/today")>=10000)
			return notify_fail(HIW"老魔提醒你：你的扫荡此时已经用完啦。\n"NOR);

	if (me->is_fighting())
		return notify_fail("临阵磨枪？来不及啦。\n");

	suanfa=cishu*fanbei;
    me->add("shimen/today",cishu);
	me->add("saodang",cishu);
	me->add("combat_exp",(5000+jiacheng)*suanfa);//修为
	me->add("potential",(5000+jiacheng)*suanfa);//潜能
	me->add("experience", (15+jiacheng)*suanfa);//体会
	if(me->query("shen")>0)
	{
	me->add("shen", (15+jiacheng)*suanfa);//正神
	}
    else
	{
    me->add("shen", -(15+jiacheng)*suanfa);//正神
	}
	me->add("score", (15+jiacheng)*suanfa);//阅历
	me->add("weiwang", (15+jiacheng)*suanfa);//威望				
	me->add("jifeng",(4+jiacheng)*suanfa);	
	tell_object(me, "扫荡成功。你扫荡了"+cishu+"次，获得"+(4+jiacheng)*suanfa+"点券"+(5000+jiacheng)*suanfa+"修为"+(5000+jiacheng)*suanfa+"潜能"+(15+jiacheng)*suanfa+"体会"+(15+jiacheng)*suanfa+"正神"+(15+jiacheng)*suanfa+"阅历"+(15+jiacheng)*suanfa+"威望\n");
	return 1;
}



int help(object me)
{
	write(@HELP
指令格式 : arg  <次数>

这个指令可以让你扫荡师门次数 来获取奖励 但是无法触发物品奖励哦
HELP
	);
	return 1;
}
