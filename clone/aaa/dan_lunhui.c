// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "�ֻص�" NOR, ({ "lunhui dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ĵ�ҩ��ʹ�ú���Դ��°�ʦѧ�գ����Ҳ�������ܡ�"+HIR+"ע�⣺ʹ�ú���Ϊ����500����ѧ��������180����\n"NOR);
		set("unit", "��");
		set("value", 20000);
		set("yuanbao", 30800);
	    set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("no_shop", 1);//�¼�
		set("only_do_effect", 1);
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;
	CHANNEL_D->do_channel( this_object(), "rumor","��˵"+me->query("name")+"������һ��"+this_object()->query("name")+""HIM"�������һ������ѡ��ʦ�ŵĻ��ᣡ");
	me->delete("family");
	me->delete("title");
	me->delete("class");

		me->set("combat_exp",5000000);
		me->set_skill("martial-cognize",180);		
		
	me->add("lunhui",1);	
	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }