// shedan.c

//inherit ITEM;
#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
string *fishs=({"����","����","����"});
int i=random(sizeof(fishs));
void create()
{
	set_name("��ͨ��"+fishs[i], ({"puton fish", "yu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "��");
		set("base_value", 3000);
		set("long", "����һ�������������ʵ�"+fishs[i]+"��\n");
		set("base_weight", 1);
	}
	setup();
}
