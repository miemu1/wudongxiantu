
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "������ʯ" NOR, ( {"lingl shis"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "����һ����Զ���װ����������ʯ��"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("yuanbao", 100);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIR "��ʯ" NOR);
		set("can_make", "all");
		set("power_point", 1);
	}
}

int query_autoload() { return 1; }