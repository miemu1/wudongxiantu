
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "��ħ��ʯ" NOR, ( {"tian jings5", "tians5", "jings5"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "�ռ��������ϣ����Դ��˾���ʥ�������������ħ��������仯���ɣ�"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("tianji1", 150);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "��ħ" NOR);
		set("can_make", "all");
		set("power_point", 4000);
	}
}

int query_autoload() { return 1; }