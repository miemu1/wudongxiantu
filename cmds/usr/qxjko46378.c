// flyto.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string home;
	object obj;
	string msg;
	
	if (! arg) return notify_fail("��Ҫ�ɵ��Ķ�ȥ��\n");

	obj = MESSAGE_D->find_user(arg);
	if (! obj) obj = find_living(arg);
	if (! obj || ! me->visible(obj))
		return notify_fail("û�������һ����\n");
		
	if (environment(me)->query("fuben2"))
		return notify_fail("���ڸ����ڲ���ʹ�ø�ָ�\n");	
			
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_ghost()) 
		return notify_fail("���㻹������˵�ɡ�\n"); 
		
	if (me->is_in_prison())   
		return notify_fail("�����������ء�\n");

	if (! me->query("born"))
		return notify_fail("�㻹û�г����أ�\n");

	if (me->query("doing"))
		return notify_fail("�㻹���ʲô����\n");
				
	while (obj && obj->is_character())
		obj = environment(obj);

	if (obj == environment(me))
		return notify_fail("����������ǰô���ҷɸ�ɶ��\n");

	if (! obj) return notify_fail("������û�л������� flyto��\n");
	if (! me->query("env/invisible"))
		message("vision", me->name() + "��ƮƮ�ķ���������\n",
			environment(me), ({ me }));
	tell_object(me, "���ˣ����ˣ�����ඣ�����\n");
	if (! me->query("env/invisible"))
		message("vision", me->name() + "����������������������\n", obj);
	me->move(obj);
	return 1;
}
