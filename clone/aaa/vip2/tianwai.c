
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"����"HIY"��"HIC"ʯ" NOR, ({"magic stone", "tianwai", "tianwai"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIY"Ԫ���ʮ�������˲��꣬ɱ�ǽ�������ʯ��ء�"NOR"\n");
		set("spectxt", "��������Ĳ��ϡ�\n");
		set("unit", "��");
		set("no_put", 1);
		set("value", 80000000);
		set("shenbing",10);
		set("yuanbao", 62222);
		set("no_give",1);
		set("no_shop", 1);//�¼�
		 set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
		set("item_origin", 1);
		set("material_attrib", "magic stone");
		set("material_name", HIY "����"MAG"��ʯ" NOR);
		set("can_make", "all");
		//set("not_make", ({ "ս��", "����", "����" }));
		set("power_point", 600);
	}
}

int query_autoload() { return 1; }