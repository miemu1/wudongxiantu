// sunfenger.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIY "��ɽ��", ({ "shushan jian" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ɽ�ɵ�����֮����\n");
                set("no_put", 1);
				set("no_give", 1);
				set("no_drop", 1);
				set("no_sell", 1);
                set("no_sun", 1);
                set("no_get", 1);
				set("no_steal", 1);
                set("xy_money", 650);
                set("base_weight", 10);
                set("base_unit", "��");
        }
        set_amount(1);
        setup();
}

void init()
{
        add_action("do_flyto", "flyto");
}

int do_flyto(string arg)
{
        object me;
        object who;
        object env;

        if (! query_amount())
                return 0;
        me = this_player();
        if (! arg)
                return notify_fail("���������ӣ�\n");

        who = find_player(arg);
        if (! objectp(who)) who = find_living(arg);
        if (! objectp(who))
                return notify_fail("�Ҳ���λ���Ӳ���ȥ��\n");

        if (! objectp(env = environment(who)))
                return notify_fail("���������Ű��Ҳ���Ŀ�꣡\n");

		if (me->is_ghost())
			return notify_fail("����ѹ���ɢ�����ðɡ�\n");

		if (! wizardp(me) && wizardp(who))
			return notify_fail("���뱻����\n");

		if (! wizardp(me) && userp(who))
			return notify_fail("�㲻���ӵ�������ϡ�\n");

        if (env == environment(me))
                return notify_fail("������ˣ�\n");

		if (who->query("newbie") && !(who->query("born")))
		{
			tell_object(me,"������suicide��㣡\n");
			return 1;
		}


	if (who->query("combat_exp") <= 100000)
	{
		tell_object(me,"���������֣�\n");
		return 1;
	}

	if (environment(who)->query("no_magic"))
		return notify_fail("���Ӳ����ǵط���\n");

	if (me->is_busy())
		return notify_fail("����æ������˵��\n");

	if (me->query("doing"))
		return notify_fail("����ƻ�������˵��\n");

        message_vision(HIM "$N" HIM "�ٻ���һ�Ѵ�Ĭ��ھ���"
                       "ֻ���ɽ���ҡ֮�ϣ������ȥ��\n"
                       "ֻ����ಡ���һ�£�$N" HIM "������ȥ��"NOR"\n",
                       me);
        message("vision", HIM "����ʱ��һ��Ť����" + me->name() + HIM
                              "����������ɽ���"NOR"\n", env);
        tell_object(me, HIM "������ǰ�����š���������ûע��ǰ���ǳ���..."NOR"\n");
        me->move(env);

        return 1;
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
        int amt;

        if (sscanf(param, "%d", amt) == 1)
                set_amount(amt);
}
