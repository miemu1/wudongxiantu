//by ���� ranger's ednpc tools.
// chukou.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��������");
	set("long","�����Ǹ������ڣ�����Ա��δ�趨������ϸ������");
	set("fuben2",1);
	set("exits", ([
		"west" : __DIR__"xiaolu14",
	]));
	set("objects", ([
	]));
	set("action_list", ([
		HIR"�˳�����"NOR:"out_fuben yes",
	]));
	setup();
}
void init()
{
	add_action("out_fuben","out_fuben");
}
int out_fuben(string arg)
{
	object me = this_player();
	string str;

	if (me->is_busy()) {
		tell_object(me, "����æ����˵��\n");
		return 1;
	}

	if (me->is_fighting()) {
		tell_object(me, "����������˵��\n");
		return 1;
	}

	if (!arg) {
		str = sprintf("%s", "�˳�����(��������):out_fuben yes" + ZJSEP);
		str += sprintf("%s", "ȡ��:out_fuben no");
		tell_object(me, ZJOBLONG+"\n"+ZJOBACTS2+ZJMENUF(2,2,9,38) + str+"\n");
	}
	else if (arg == "yes"){
		tell_object(me, HIC+"ɾ��Ŀ¼(/fuben/"+me->query("id")+"/jinbing1)��\n"NOR);
		if (me->query("fuben/jinbing1")) {//�����������
			"/adm/daemons/fuben_jinbing1"->dest_fb(me);
			me->delete("fuben/jinbing1");
		}
		me->move("/d/city/wumiao");
	} else
		tell_object(me, "��������ڸ����\n");
	return 1;
}
int no_reset() {return 1;}
