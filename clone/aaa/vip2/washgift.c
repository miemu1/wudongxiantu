// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit ITEM;

string *valid_types = ({
        "sword",
        "blade",
        "staff",
        "hammer",
        "club",
        "whip",
        "throwing",
});

int do_washto(string arg);

void create()
{
        set_name(HIR "ϴ�㵤[��]" NOR, ({"wash wan", "wash"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
�����ṩ����Щϴ���Ե�������һ�����·����������Եĵ�ҩ��
��ʽΪ washto <����> <����> <����> <��> ���磺
washto 20 20 20 20 ��ע�⣬ϴ�������Կ��ܻᵼ����
�Ĳ����书�޷�ʹ�ã�������ʹ��ǰ���濼�������
LONG );
                set("yuanbao", 1000);
                set("no_sell", 1);
				set("no_get", 1);
				set("no_give", 1);
				set("no_drop", 1);
				set("no_put", 1);
					
        }
        setup();
}

void init()
{
        object me = this_player();

        if (me == environment())
                add_action("do_washto", "washto");
}


int do_washto(string arg)
{
        int i, j, points;
        int tmpstr, tmpint, tmpcon, tmpdex;
        int str, wux, con, dex;
        object me, weapon;
        mapping my;
        string *sname;
        mixed skill_status;

        me = this_player();

        if (! arg || sscanf(arg, "%d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) != 4)
                return notify_fail("ָ���ʽ��washto <����> <����> <����> <��>\n" +
                                   "��    �磺washto 20 20 20 20\n");

    
        if (tmpstr > 1500 || tmpstr < 13)
                return notify_fail("��������ѡ���������ֵ���Լ����Ե�" + points + "��ֵ��һ�¡�\n");

        if (tmpint > 1500 || tmpint < 13)
                 return notify_fail("��������ѡ���������ֵ���Լ����Ե�" + points + "��ֵ��һ�¡�\n");

        if (tmpcon > 1500 || tmpcon < 13)
             return notify_fail("��������ѡ���������ֵ���Լ����Ե�" + points + "��ֵ��һ�¡�\n");
        if (tmpdex > 1500 || tmpdex < 13)
                 return notify_fail("��������ѡ���������ֵ���Լ����Ե�" + points + "��ֵ��һ�¡�\n");

        my = me->query_entire_dbase();
        str = copy(my["str"]);
        wux = copy(my["int"]);
        con = copy(my["con"]);
        dex = copy(my["dex"]);

        points = str + wux + con + dex;
        if (tmpstr + tmpint + tmpcon + tmpdex != points)
                return notify_fail("��������ѡ���������ֵ���Լ����Ե�" + points + "��ֵ��һ�¡�\n");


        write("�����·�����츳Ϊ\n"
              "����[" + tmpstr + "]\n"
              "����[" + tmpint + "]\n"
              "����[" + tmpcon + "]\n"
              "��[" + tmpdex + "]��\n");

        my["str"] = tmpstr;
        my["int"] = tmpint;
        my["con"] = tmpcon;
        my["dex"] = tmpdex;

        me->set("washed", 1);
		UPDATE_D->check_skill(me);
		me->set("usesxidian", time());
		me->save();

        write("�����·���������Գɹ��������ۺ����Բ鿴��\n");
        destruct(this_object());
        return 1;
		
}

