// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "����" NOR, ({ "caomin dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ө��͸�ĵ�ҩ����̫���Ͼ����ƶ��ɣ�����֮��ʹ��ǿ��ɢȥ�����书���Ӷ����°�ʦѧ��,�������ǰ��ѧ���ܡ�ʹ��ǰ����ж������title\n");
		set("unit", "��");
		set("value", 1);
				set("no_give",1);
				set("no_drop",1);
				set("no_get",1);
				set("no_sell",1);
                set("no_put", 1);
		set("tianji1", 25);
		set("only_do_effect", 1);
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;
	mapping all_fam = ([
		"�䵱��":({
				
			}),
		"������":({
				
//����Ϊ���ֲؾ��������书
				
			}),
		"������":({
			}),
		"��ɽ��":({
			}),
		"��ɽ����":({
				
			}),
		"������":({
				
			}),
		"�һ���":({
				
			}),
		"������":({
				
			}),
		"ؤ��":({
				
				
			}),
		"��Ĺ��":({
				
			}),
		"ȫ���":({
				
			}),
		"������":({
				
			}),
		"��ң��":({
			}),
		"ѩɽ��":({
				
			}),
		"Ѫ����":({
			}),

		"���չ�":({
				
			}),
		"Ľ������":({
			}),
		"ŷ������":({
				
			}),
		"�������":({
			
			}),
		"���ϻ���":({
				
			}),
	]);


	if(!me->query("family"))
	{
		tell_object(me,"�㻹û��ʦ�Űɣ�����ʹ��"+query("name")+"��\n");
		return 1;
	}
	message_vision(CYN "$N" CYN "С�ĵķ�����һ"+query("unit")+"" + name() + CYN "�������������ˡ�"NOR"\n", me);

	family = me->query("family/family_name");

	
	CHANNEL_D->do_channel( this_object(), "rumor","��˵"+me->query("name")+"������һ��"+this_object()->query("name")+""HIM"�������һ������ѡ��ʦ�ŵĻ��ᣡ");
	me->delete("family");
	me->delete("title");
	me->delete("class");
	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }