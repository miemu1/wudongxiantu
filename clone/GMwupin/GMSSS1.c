
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "���𺡹�" NOR, ( {"GMSSS1"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "����һ�����𾳸��ֵ�ʬ�ǣ���������������ϲ��ϣ�"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 100000000);
		set("tianji1", 100000000);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIR "����" NOR);
		set("can_make", "all");
		set("power_point", 9999999);
	}
}

int query_autoload() { return 1; }