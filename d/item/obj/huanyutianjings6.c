
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "����Դʯ" NOR, ( {"tian jings6", "tians6", "jings6"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "�ռ��������ϣ���ħ��ʯ���ռ������棡"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 1);
		set("tianji1", 200);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "����" NOR);
		set("can_make", "all");
		set("power_point", 5000);
	}
}

int query_autoload() { return 1; }