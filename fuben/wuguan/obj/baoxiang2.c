//baoxiang.c

#include <ansi.h>
inherit ITEM;
//�������
string *random_item = ({
    "/clone/shizhe/jinsha",
});

void create()
{
	set_name("����", ({ "bao xiang" }));
	set("long", "һ�����䣬����"+ZJURL("cmds:open_1 bao xiang")+ZJSIZE(22)+"��"NOR+"��������\n");
	set("unit", "��");
	set("value", 10);
	set("no_get", "���ӷ·����˸�һ������ʹ�����̵�����Ҳ�᲻����");
	set("action_list", ([
		"��" : "open_1 bao xiang",
	]));
	set_weight(1000000);
	
	setup();
}
void init()
{
	add_action("do_open_1", "open_1");
}
int do_open_1(string arg)
{
	string id = random_item[random(sizeof(random_item))];//�������Ʒ�б�
	object ob, obj;
	object me = this_player();
	object player;
	int i,num;
	object oba, obb, obc;
	int ok = 0;
	object *obs = all_inventory(environment(this_object()));
	
	if (!arg || arg != "bao xiang")
		return notify_fail("�����ʲô����\n");
	
	oba = present("wuguan jiaotou", environment(me));
	oba = present("shouling", environment(me));	
	oba = present("gaoshou", environment(me));	
	oba = present("tongling", environment(me));
	oba = present("duizhang", environment(me));		
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				tell_object(player, oba->name()+"Ҫ��������ȴ���ң�\n");
				ok = 1;
			}
		}
	}
	if (ok > 0)
		return 1;
	message_vision( "$N����" + name() + "��"NOR"\n", me);
	
	if (!query("open_1")) {
	    num=10+random(me->query("kar"));
    if (me->query("kar")< 20 &&random(101) < 30||me->query("kar") > 20 &&random(101) > 30){	    	
		me->add("yuanbao_2",num);
		tell_object(me, "��ϲ����"+num+"��ʯƱ��\n");
		set("open_1", 1);		
	}else
		tell_object(me, "��������������Ǻܺã����ӻ����ˡ�\n");		
        set("open_1", 1);		
	} else 
		tell_object(me, "���������Ķ����Ѿ������ù��ˡ�"NOR"\n");
	
	return 1;
}
