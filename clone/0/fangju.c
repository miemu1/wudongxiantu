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
	set_name(HIG"��������ʯ", ({"sjss"}));	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10);
		set("coin", 1);
          
  set("base_unit", "��");       
  set("no_drop",1); 
  set("no_give",1);
            set("no_get",1);				
            set("no_put",1);				
		set("base_weight", 10);
		set("yuanbao",2000);
		set("long",HIW"ʹ���·��ȼ��ɼ�1����\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if((me->query("jia/make")) )
		    return notify_fail("�㻹û�����Ʒ���(�·�)�أ�����ʹ��"+ name() +"��\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	me->add("jia/lv",1);
        

	write(HIW"����·��ȼ�����һ�����ǵ������ص�ˢ�¹�������"NOR"\n");

    return 1;
}
