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
	    tell_object(me,HIY"��Ŀǰû�а�ᣡ"NOR"\n"); 
		return;
   }
   if(str=="1")a=1;
   else if(str=="10")a=10;
   else a=1;
   if(!str)
   {
	msg = ZJOBLONG+""HIY"��ѡ����Ҫ�����Ĵ�����"+ZJBR+"��Ŀǰһ����"+BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("id"))+"��ﹱ"+ZJBR+"��Ŀǰ������"+me->query("bangggongji")+"�������������������1000��"+ZJBR+"100�㡼"HIC"�ﹱ"HIG"������һ�Σ�"NOR"\n";			
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
	msg += "����һ��"":wujue 1"+ZJSEP;
	msg += "����ʮ��"":wujue 10"+ZJSEP;
	write(msg + "\n");
	return 1;
   }
   if(a<0)
   return notify_fail("����\n");
   if(!BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("id"))
	||BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("id")) <a*100)
	return notify_fail(ZJOBLONG"��Ĺ��׶Ȳ��㣡\n");
	if (BANGHUI_D->query_banghui(short+"/level") <1)
			return notify_fail("��û��������\n");
	if (BANGHUI_D->query_banghui(short+"/level") <2&&me->query("bangggongji")>=300)
			return notify_fail("��ǰ���û�а취������̫���ˣ�\n");
	if (BANGHUI_D->query_banghui(short+"/level") <3&&me->query("bangggongji")>=600)
			return notify_fail("��ǰ���û�а취������̫���ˣ�\n");
	if (BANGHUI_D->query_banghui(short+"/level") <4&&me->query("bangggongji")>=900)
			return notify_fail("��ǰ���û�а취������̫���ˣ�\n");
   if(me->query("bangggongji")>=1000)
   return notify_fail("��û���������ˣ�\n");
   hh=0;
   for(i=0;i<a;i++){
	   kk=3+random(4);
	   hh+=kk;
   }
   me->add("gain/damage",hh);
   me->add("bangggongji",hh);
   BANGHUI_D->set_banghui(short+"/gongxian/"+me->query("id"), BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("id"))-(a*100));
   tell_object(me,HIY"��������"+a*100+"��ﹱ������"+hh+"������������"NOR"\n");
   tell_object(me,ZJFORCECMD("wujue"));
   return 1;
}

int help (object me)
{

	return 1;
}