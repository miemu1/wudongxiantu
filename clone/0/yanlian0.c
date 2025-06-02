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
	set_name(HIR"��������", ({"hubo"}));	if( clonep() )
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
		set("zjvip/all_pay",350);
		set("long",HIW"����һ�������ؼ���һ��������ʹ�á�\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	me->set_skill("jiuyang-shengong",350);
	me->set_skill("taixuan-gong",360);
	me->set_skill("six-finger",360);
	me->set_skill("dragon-strike",360);
	me->set_skill("qiankun-danuoyi",360);
	me->set_skill("jiuyin-shengong",360);
	me->set_skill("taiji-shengong",360);
        

	write(HIW"������300�������񹦣�"NOR+HIG"��л����Ц���Ĵ���֧�֣�ף����Ϸ��죡"NOR"\n");

    return 1;
}
