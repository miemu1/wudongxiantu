#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"�����ķ�"NOR, ({ "daojiaxf"}));
	set("long","����һ��"HIG"�����ķ�"NOR"��ʹ������Ϊ0��360"ZJURL("cmds:kan daojiaxf")+ZJSIZE(28)+"�о�"NOR"��\n");
	set("unit","��");
	set_weight(100);
	set("value",30000);
	set("yuanbao",250);	
    set("no_steal",1);
	set("desc","�����ķ�");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="daojiaxf")
  	return notify_fail("��Ҫ��ʲô?\n");
      		
 if(me->query_skill("taoism") < 0)
			return notify_fail("������ڵ���֪̫���� ��\n");
 
 if(me->query_skill("taoism") > 359)
			return notify_fail("�����ķ��Ѿ��ﲻ�� ��\n");

  me->set_skill("taoism", me->query_skill("taoism",1) + 25);

	write(HIY"���о�"HIG"�����ķ�"HIY"ˢ�����Լ������ڵ���֪!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }