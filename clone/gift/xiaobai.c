
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

string *types = ({
	"force",
	"dodge",
	"unarmed",
	"cuff",
	"strike",
	"finger",
	"hand",
	"claw",
	"sword",
	"blade",
	"staff",
	"hammer",
	"club",
	"whip",
	"parry",
});

void create()
{
	set_name("��ħ�ĲƲ�", ({"xiaobai libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��ʦ�׵ĲƲ���\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 10);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i,num1,num2,num3,num4;
	object gong,bagua,jian,jiuzhuan;

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");


	message_vision("$N����һ" + query("unit") + name() + "��\n", me);
	
	jian = new("/clone/jifeng/book_wuliang");
	jian->set_amount(24);
	write(YEL"��ϲ���������"+jian->short()+"��"NOR"\n");
	jian->move(me);
	bagua = new("/clone/jifeng/kuilei");
	bagua->set_amount(5);
	write(YEL"��ϲ���������"+bagua->short()+"��"NOR"\n");
	bagua->move(me);
	jiuzhuan = new("/clone/jifeng/putao");
	jiuzhuan->set_amount(24);
	write(YEL"��ϲ���������"+jiuzhuan->short()+"��"NOR"\n");
	jiuzhuan->move(me);

	for(i=0;i<sizeof(types);i++)
	{
		if(me->query_skill(types[i],1)<100)
		{
			//me->set_skill(types[i],100);
			//tell_object(me,"��ѧ������100��"+to_chinese(types[i])+"��\n");
		}
	}

	add_amount(-1);
	me->save();

	return 1;
}
