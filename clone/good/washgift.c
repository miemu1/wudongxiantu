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
        set_name(HIR "ϴ�㵤" NOR, ({"wash wan", "wash"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
�����ṩ����Щϴ���Ե�������һ�����·����������Եĵ�ҩ��
��ʽΪ washto <����> <����> <����> <��> ���磺
washto 30 30 30 30 ��ע�⣬ϴ�������Կ��ܻᵼ����
�Ĳ����书�޷�ʹ�ã�����ÿ��ֻ��һ�λ��ᣬ
������ʹ��ǰ���濼�������
LONG );
                set("value", 1);
                set("no_sell", 1);
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

        if (me->query("gift/washed")>2)
                return notify_fail("���Ѿ�ʹ�ù�ϴ�츳���ˣ�ÿ��ֻ�ж��λ��ᡣ\n");

        if (tmpstr > 45 || tmpstr < 30)
                return notify_fail("����ѡ���������ֵҪ�������30��45֮�䡣\n");

        if (tmpint > 45 || tmpint < 30)
                return notify_fail("����ѡ���������ֵҪ�������30��45֮�䡣\n");

        if (tmpcon > 45 || tmpcon < 30)
                return notify_fail("����ѡ��ĸ�����ֵҪ�������30��45֮�䡣\n");

        if (tmpdex > 45 || tmpdex < 30)
                return notify_fail("����ѡ�������ֵҪ�������30��45֮�䡣\n");

        my = me->query_entire_dbase();
        str = copy(my["str"]);
        wux = copy(my["int"]);
        con = copy(my["con"]);
        dex = copy(my["dex"]);

        points = str + wux + con + dex;
        if (tmpstr + tmpint + tmpcon + tmpdex != points)
                return notify_fail("��������ѡ���������ֵ���Լ����Ե�" + points + "��ֵ��һ�¡�\n");
/*
        write(HIW "��ʼ���������������ѧ�����Ƿ�������������...\n" NOR);

        skill_status = me->query_skills();
        if (mapp(skill_status) && sizeof(skill_status))
        {
                int ob;

                if (objectp(ob = me->query_temp("weapon")))
                        ob->unequip();

                me->delete_temp("handing");

                sname  = keys(skill_status);

                for (i = 0; i < sizeof(sname); i++)
                {
                        if (SKILL_D(sname[i])->type() != "martial")
                                continue;

                        if (sname[i] == "zuoyou-hubo")
                                continue;

                        if (sname[i] == "martial-cognize" || sname[i] == "sword-cognize")
                                continue;

                        if (sname[i] == "count" && tmpint >= 30)
                                continue;

                        for (j = 0; j < sizeof(valid_types); j++)
                        {
                                if (SKILL_D(sname[i])->valid_enable(valid_types[j]))
                                {
                                        switch(valid_types[j])
                                        {
                                        case "sword" :
                                                weapon = new("/clone/weapon/changjian");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "blade" :
                                                weapon = new("/clone/weapon/changjian");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "staff" :
                                                weapon = new("/clone/weapon/zhubang");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "whip" :
                                                weapon = new("/clone/weapon/changbian");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "club" :
                                                weapon = new("/clone/weapon/qimeigun");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "hammer" :
                                                weapon = new("/clone/weapon/hammer");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "throwing" :
                                                weapon = new("/d/tangmen/obj/qinglianzi");
                                                weapon->move(me, 1);
                                                me->set_temp("handing", weapon);
                                                break;
                                        default :
                                                break;
                                        }
                                        break;
                                }
                        }
                        if (! SKILL_D(sname[i])->valid_learn(me))
                        {
                                if (objectp(weapon))
                                        destruct(weapon);

                                return notify_fail(HIR "������ yanjiu " + sname[i] + " 1��ȷ�Ͽ����о�����ϴ�����ԡ�\n" NOR);
                        }

                        if (objectp(weapon))
                                destruct(weapon);
                }
        }*/

        write("�����·�����츳Ϊ\n"
              "����[" + tmpstr + "]\n"
              "����[" + tmpint + "]\n"
              "����[" + tmpcon + "]\n"
              "��[" + tmpdex + "]��\n");

        my["str"] = tmpstr;
        my["int"] = tmpint;
        my["con"] = tmpcon;
        my["dex"] = tmpdex;
/*
        write(HIW "��ʼ�������������ѧ�����Ƿ�����ѧϰ����...\n" NOR);

        if (mapp(skill_status) && sizeof(skill_status))
        {
                int ob;

                if (objectp(ob = me->query_temp("weapon")))
                        ob->unequip();

                me->delete_temp("handing");

                sname  = keys(skill_status);

                for (i = 0; i < sizeof(sname); i++)
                {
                        if (SKILL_D(sname[i])->type() != "martial")
                                continue;

                        if (sname[i] == "zuoyou-hubo")
                                continue;

                        if (sname[i] == "martial-cognize" || sname[i] == "sword-cognize")
                                continue;

                        if (sname[i] == "count" && tmpint >= 30)
                                continue;

                        for (j = 0; j < sizeof(valid_types); j++)
                        {
                                if (SKILL_D(sname[i])->valid_enable(valid_types[j]))
                                {
                                        switch(valid_types[j])
                                        {
                                        case "sword" :
                                                weapon = new("/clone/weapon/changjian");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "blade" :
                                                weapon = new("/clone/weapon/changjian");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "staff" :
                                                weapon = new("/clone/weapon/zhubang");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "whip" :
                                                weapon = new("/clone/weapon/changbian");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "club" :
                                                weapon = new("/clone/weapon/qimeigun");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "hammer" :
                                                weapon = new("/clone/weapon/hammer");
                                                weapon->move(me, 1);
                                                weapon->wield();
                                                break;
                                        case "throwing" :
                                                weapon = new("/d/tangmen/obj/qinglianzi");
                                                weapon->move(me, 1);
                                                me->set_temp("handing", weapon);
                                                break;
                                        default :
                                                break;
                                        }
                                        break;
                                }
                        }
                        if (! SKILL_D(sname[i])->valid_learn(me))
                        {
                                if (objectp(weapon))
                                        destruct(weapon);

                                my["str"] = str;
                                my["int"] = wux;
                                my["con"] = con;
                                my["dex"] = dex;
                                return notify_fail(HIR "�����Բ�������" + to_chinese(sname[i]) + "ѧϰ�������޸�ʧ�ܡ�\n" NOR);
                        }

                        if (objectp(weapon))
                                destruct(weapon);
                }
        }
		*/
        me->set("gift/washed", 1);

        write("�����·���������Գɹ���������ָ��(score)�鿴��\n");
        destruct(this_object());
        return 1;
}

