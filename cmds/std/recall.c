#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	string str;
	object ob;
 
	
	
	if (arg == "ce")
	{			
        if (me->is_fighting())
			return notify_fail("��������ȦȦ��ʱ�򣬱�С��һ�����˳�����\n");
		if (me->query_temp("jun_quest/party"))
			return notify_fail("�㻹����ս����ʹ�ã���\n");

	if (! me->query("born"))
		return notify_fail("�㻹û�г����أ�\n");
	
	if (me->is_ghost()) 
		return notify_fail("���㻹������˵�ɡ�\n"); 
	
		if (present("biao huo", me))
			return notify_fail("�����ϴ�������������ʩչ��\n");
		
		if (present("letter", me) || present("receipt", me)) 
			return notify_fail("�����ϴ����ܺ�������ʩչ��\n");
		
		file = "/d/city/kedian";
		
		if (base_name(environment(me)) == file)
			return notify_fail("���Ѿ������ݿ͵��ˡ�\n");
			
		if (! get_object(file))
			return notify_fail("��о����ƺ���ʲô���Ծ���\n");

		message("vision", me->name() + "������������ǰ���ٻ���һ��Բ������������ǰ��"
			"�ռ䣬ֻ��Բ�ڵĿռ���ս�" + me->name() + "�����˽�ȥ��\n",
			environment(me), ({me}));
		
		tell_object(me, "��ӿ͵��ĳ������ռ��ѷ��������\n");

		me->move(file);
		message("vision", me->name() + "�ӿ͵��ĳ������ռ��ѷ��������\n",
			environment(me), ({me}));

		return 1;
	}

   
	
	
	

	return 1;
}


