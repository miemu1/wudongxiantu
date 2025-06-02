
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

void create()
{
	set_name(HIR "����[��]" NOR, ({"bao zhu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������һ�ֽ�"HIR"��"NOR"�Ĺ��ޣ�ͷ�����ǣ������쳣��������Ӻ��ף�ÿ����Ϧ�����ϰ�����ʳ�����˺���������������żȻ��ȼ����"
					"����������ž�������������������ޣ���˸��֡��������������������γ����л�����ϵ�һ�ִ�ͳ��\n");
		set("base_unit", "��");
		set("no_shop", 1);//�¼�
		set("yuanbao", 8);
		set("base_value", 50000);
		set("base_weight", 1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
    }
	setup();
}
