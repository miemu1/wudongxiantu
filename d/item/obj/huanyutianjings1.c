
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "��Ԩ֮ʯ" NOR, ( {"tian jings1", "tians1", "jings1"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "�ռ��������ϣ����Դ���ħԴ��ʯ����׹��ħ����Ԩ֮���ݻ����ɣ�"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("tianji1", 75);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "��Ԩ" NOR);
		set("can_make", "all");
		set("power_point", 2500);
	}
}

int query_autoload() { return 1; }