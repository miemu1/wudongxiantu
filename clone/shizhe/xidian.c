// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "�޳���" NOR, ({ "wuchang dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ө��͸�ĵ�ҩ������֮��ʹ��ǿ��ɢȥ���м��ܣ�����Ͷ̥ת����\n");
		set("unit", "��");
		set("value", 50000);
		set("yuanbao", 50);
		set("only_do_effect", 1);
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;

	message_vision(CYN "$N" CYN "С�ĵķ�����һ"+query("unit")+"" + name() + CYN "�������������ˡ�"NOR"\n", me);

	CHANNEL_D->do_channel( this_object(), "rumor","��˵"+me->query("name")+"������һ��"+this_object()->query("name")+""HIM"�����½����ֻأ�");
	me->delete("family");
	me->delete("title");
	me->delete("class");
	me->delete("startroom");
	me->delete("born");
	me->delete("born_family");
	me->delete("character");
	me->delete("type");
	log_ufile(me,"wuchang","����Ͷ̥�ˡ�\n");
	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }