//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string str)
{
   int i,k,a,hh,kk;
   string msg,short;
   object ob;
   if(!(short=me->query("banghui/name")))
   {
	    tell_object(me,HIY"你目前没有帮会！"NOR"\n"); 
		return;
   }
   if(str=="1")a=1;
   else if(str=="10")a=10;
   else a=1;
   if(!str)
   {
	msg = ZJOBLONG+""HIY"请选择你要提升的次数！"+ZJBR+"你目前一共有"+BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("id"))+"点帮贡"+ZJBR+"你目前提升了"+me->query("bangggongji")+"点真气攻击，最大提升1000点"+ZJBR+"100点〖"HIC"帮贡"HIG"〗提升一次！"NOR"\n";			
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
	msg += "提升一次"":wujue 1"+ZJSEP;
	msg += "提升十次"":wujue 10"+ZJSEP;
	write(msg + "\n");
	return 1;
   }
   if(a<0)
   return notify_fail("错误！\n");
   if(!BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("id"))
	||BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("id")) <a*100)
	return notify_fail(ZJOBLONG"你的贡献度不足！\n");
	if (BANGHUI_D->query_banghui(short+"/level") <1)
			return notify_fail("你没法提升！\n");
	if (BANGHUI_D->query_banghui(short+"/level") <2&&me->query("bangggongji")>=300)
			return notify_fail("当前帮会没有办法帮助你太多了！\n");
	if (BANGHUI_D->query_banghui(short+"/level") <3&&me->query("bangggongji")>=600)
			return notify_fail("当前帮会没有办法帮助你太多了！\n");
	if (BANGHUI_D->query_banghui(short+"/level") <4&&me->query("bangggongji")>=900)
			return notify_fail("当前帮会没有办法帮助你太多了！\n");
   if(me->query("bangggongji")>=1000)
   return notify_fail("你没法再提升了！\n");
   hh=0;
   for(i=0;i<a;i++){
	   kk=3+random(4);
	   hh+=kk;
   }
   me->add("gain/damage",hh);
   me->add("bangggongji",hh);
   BANGHUI_D->set_banghui(short+"/gongxian/"+me->query("id"), BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("id"))-(a*100));
   tell_object(me,HIY"你消耗了"+a*100+"点帮贡提升了"+hh+"点真气攻击！"NOR"\n");
   tell_object(me,ZJFORCECMD("wujue"));
   return 1;
}

int help (object me)
{

	return 1;
}