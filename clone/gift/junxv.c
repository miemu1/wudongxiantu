
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
	set_name("��������", ({"junxv"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���Ǳ������裬���溬�б�����ʽװ��һ�ף�\n");
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
	object gong,bagua,jian,kai,dao,jia;

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	num1=200000;
	//me->add("combat_exp",num1);
	num2=200000;
	//me->add("potential",num2);
	num3=2000+random(100);
	//me->add("score",num3);
	num4=50+random(30);
	//me->add("weiwang",num4);
	me->set("p_master/last_learnto",me->query("combat_exp"));
	//me->add("zjvip/times",72*3600);

	message_vision("$N����һ" + query("unit") + name() + "��\n", me);
	//write(YEL"��ϲ���������"+num1+"����Ϊ��"NOR"\n");
	//write(YEL"��ϲ���������"+num2+"��Ǳ�ܡ�"NOR"\n");
	//write(YEL"��ϲ���������"+num3+"�㽭��������"NOR"\n");
	//write(YEL"��ϲ���������"+num4+"�㽭��������"NOR"\n");
	//write(YEL"��ϲ���������3���Աʱ����"NOR"\n");

	gong = new("/clone/new/beiliang/blade");
	write(YEL"���������"+gong->short()+"��"NOR"\n");
	gong->move(me);
	jian = new("/clone/new/beiliang/sword");
	write(YEL"���������"+jian->short()+"��"NOR"\n");
	jian->move(me);
	bagua = new("/clone/new/beiliang/cloth");
	write(YEL"���������"+bagua->short()+"��"NOR"\n");
	bagua->move(me);
	kai = new("/clone/new/beiliang/boots");
	write(YEL"���������"+kai->short()+"��"NOR"\n");
	kai->move(me);
	dao = new("/clone/new/beiliang/hands");
	write(YEL"���������"+dao->short()+"��"NOR"\n");
	dao->move(me);	
	jia = new("/clone/new/beiliang/pants");
	write(YEL"���������"+jia->short()+"��"NOR"\n");
	jia->move(me);
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
