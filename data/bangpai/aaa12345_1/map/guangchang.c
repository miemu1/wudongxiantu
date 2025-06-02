// by ranger_����
// banghui.c
//#include <bangpai.h>
inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", "�����ǰ��ɹ㳡�����ֵ��Ǿۻ�ĵط���");
	set("exits", ([
		"south" : __DIR__"liangong",
		"east" : __DIR__"chufang",
		"west" : __DIR__"liandan",
		"north" : __DIR__"biguan",
	]));
	set("action_list", ([
		HIG"��������"NOR:"bpquest",
	]));
		set("bangpai_room","1");
		set("bangpai/guangchang",1);
	set("no_fight","1");
	setup();
}

void init()
{
	add_action("do_quest", "bpquest");
}

int do_quest(string arg)
{
	object me;
	me = this_player();

	if (! arg || arg == "")
	{
	 string msg=ZJOBLONG;
	  msg += "Ϊ�˰��ɵķ�չ��Ϊ�˶������ڵ����������ɰ䲼���������������ȡ��\n";
	  msg += ZJOBACTS2;
	  msg += "���:bpquest grass";
			tell_object(me,msg+"\n");
			return 1;
    }		
  
		
    if (me->query("bangpai/finish")>=20)
    	return notify_fail("��������İ������񹻶��ˣ���ʱû��ʲô����������ˡ�\n");
    	
	if (arg == "grass")
	{ 
		 if (me->is_busy())
			return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
         if  (!me->query_temp("bangpai/quest/grass"))
      {
      
        me->set_temp("bangpai/quest/grass",1);
        tell_object(me,HIY"������ɲ��ϼ�ȱ����ȥ�����ϱߵ���������ݻ�������ȥ�ٻأ�\n");     
       
      }   else
        if  (me->query_temp("bangpai/quest/grass"))
      {
           object grass;
           
            if (!objectp(grass=present("quest grass",me))||grass->query_amount()<10)
        	return notify_fail("��Ĳ����أ�������ȥ��ݣ�\n");
        	
        	grass->add_amount(-10);
        	me->add("combat_exp",1000);
        	me->add("potential",1000);
        	me->delete_temp("bangpai/quest/grass");
        	me->add("bangpai/finish",1);
        	BANGHUI_D->set_banghui(me->query("banghui/name")+"/exp", BANGHUI_D->query_banghui(me->query("banghui/name")+"/exp")+10);
        	BANGHUI_D->set_banghui(me->query("banghui/name")+"/gongxian/"+me->query("id"), BANGHUI_D->query_banghui(me->query("banghui/name")+"/gongxian/"+me->query("id"))+10);
        	tell_object(me,"������1000����Ϊ��Ǳ�ܣ�10���ṱ�ף��������Ͱ���\n");      
        	 	
       }
		return 1;
	}
	return 1;
}       
