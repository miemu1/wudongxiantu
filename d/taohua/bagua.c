// /d/xiakedao/shiroom01.c ���͵� ʯ��1

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", "����һ��Сͤ�ӣ�ͤ��������һ������ʯ�̣�����ƺ��ǳ���Զ������һЩ�̻��Ѿ���Щģ�����塣" );
	set("exits", ([
		"west" : __DIR__"tao_out",
	]));
	set("item_desc", ([
		"������" : "ʯ���ϵĿ̻���Щ�ط��Ѿ���Щģ�����壬������ϸ�۲�(guanmo bugua)֮���ƺ����а���������\n"
		ZJOBACTS2"��Ħ:guanmo bagua\n",
	]));

	set("no_fight", 1);
	setup();
}

void init()
{
	add_action("do_study", "guanmo");
}

int do_study(string arg)
{
	object me;
	int lvl;

	if (arg != "bagua")
		return notify_fail("�����о�ʲô��\n");

	me = this_player();

	if (me->query("combat_exp") < 2000000)
	{
		write("�㿴�˰��죬ֻ���Լ�ʵս��Ϊ(200w)̫ǳ�����޷���������ĸ���֪ʶ��\n");
		return 1;
	}

	if (me->is_busy())
	{
		write("��������æ��û���о���\n");
		return 1;
	}

	if (me->query("family/family_name")!="�һ���" && me->query_skill("count",1)>379)
	{
		write("���Ѿ������һ������ˣ���ô������˼����������ж���ȥ��\n");
		return 1;
	}

	if ((me->query("potential") - me->query("learned_points")) < 10)
		return notify_fail("��Ŀǰ��Ǳ�ܲ��㣬�޷��Ӱ������ϸ��򵽸������ݡ�\n");

	if ( me->query_skill("count",1) < 200)
		return notify_fail("����������Ե���⻹����(200)�����ѴӰ������ϸ��򵽸������ݡ�\n");

	if (me->query("int")<38&&(int)me->query_skill("count", 1) > (int)me->query("int")*10)
		return notify_fail("����������Բ������޷�������µ��������ԡ�\n");

	if ( me->query("qi")<101 || me->query("jing") < 101)
		return notify_fail("��Ŀǰ�ľ��񲻼ѣ����ǵȻ��ٹ�Ħ�ɡ�\n");

	me->receive_damage("qi", 100);
	me->receive_damage("jing", 100);
	me->start_busy(1);

	if (random(10)>2)
	{
		write("����������İ�����·���𽥽���һ������ľ��磬�ԡ��������ԡ���ʼ��������\n");
        me->add("learned_points", 10);
        me->improve_skill("count", 10 + random(me->query("int")*3));
	} else
		write("��Ǳ����ĥ�������·����������ƫƫ��ץ��סҪ�졣\n");

	return 1;
}
