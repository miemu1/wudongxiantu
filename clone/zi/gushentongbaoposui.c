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
	set_name(HIY"����ͨ������ȱ��"NOR, ({"gushen tombo can"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1",300);
        set("no_sell",1);
        set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("unit", "ö");
		set("base_unit", "ö");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","��Ϊ�ǲ�ȱ�����Բ�֪���ᷢ��ʲô�£��о������л��£�\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
            return notify_fail("����æ���ء�\n");
	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+name()+"��\n");
		
	write(YEL"��ʹ����һö��ȱ��Ǯ����Ǯ��������������"NOR"\n");
	if ((me->query("potential")-me->query("potential"))>500000000)
                return notify_fail("���Ǳ��̫����");
      else {
	  me->add("potential",500000);//Ǳ��
	write(HIM"��������ʮ��Ǳ�ܣ�"NOR"\n");}
	if ((me->query("combat_exp")-me->query("combat_exp"))>500000000)
		return notify_fail("�����Ϊ̫����");
      else 
	if (random(9)<=2) {
		me->add("combat_exp",50000000);//��Ϊ
		write(HIM"��ϲ��ʮ��֮���ĸ������������ǧ����Ϊ!"NOR"\n");
		}
		if ((me->query("magic_points")-me->query("magic_points"))>500000000)
		return notify_fail("������̫����");
      else 
	if (random(9)==1){
	me->add("magic_points",5000000);//���
	write(HIM"��ϲ��ʮ��֮һ�ĸ������������������!"NOR"\n");
	}
	if (random(4)==1) {
            me->add("per",1);
			message_vision(HIW"ֻ��$N���Ϸ���һ��ҫ�۵İ׹⣬�ƺ�������ʲô��������顣"NOR"\n", me);
            write(HIM"��ϲ�����������ò������!"NOR"\n");
            }
			
			
	add_amount(-1);
	return 1;
}