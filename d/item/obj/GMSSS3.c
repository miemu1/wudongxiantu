
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "��������" NOR, ( {"zhenl gu"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "����һ��������ʬ�ǣ���������������ϲ��ϣ�"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("yuanbao", 100);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIR "����" NOR);
		set("can_make", "all");
		set("power_point", 15000);
	}
}

int query_autoload() { return 1; }