// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit ROOM;

int do_suicide1(string arg);
int do_suicide2(string arg);
void create()
{
        set("short", "��Ѩ");
        set("long","ɽ�����ض����������䣬����������֮��������һ�㣬���շ�
�������й�֮��Խ������Խ����ʪ��������������Ѽ���ָ����Ѩ���涼��ɽ��������������ɽ�ȳ�ʪ�����ʣ������Ǹ���ԡ�Ĵ�Ů����Ѩ���ıڻ�����ͼ��������ȴ�����˼䣬�������ϡ�\n" ZJURL("cmds:ci hou")+ZJSIZE(20)+HIC"�̺�"NOR"\n"
ZJURL("cmds:zhuang qiang")+ZJSIZE(20)+HIY"ײǽ"NOR"\n"  );
        set("coor/x",2000);
        set("coor/y",-210);
        set("coor/z",0);
        set("no_magic",1);
        set("no_spells",1);
        set("no_fight",1);
        set("no_get_from",1);
        setup();
}

void init()
{
        add_action("do_suicide1", ({ "ci hou", "ci" }));
        add_action("do_suicide2", ({ "zhuang qiang", "zhuang" }));
}

int do_suicide1(string arg)
{
        object weapon;
        object me = this_player();

        weapon = me->query_temp("weapon");

        if (! weapon)
                return notify_fail("��û����������ô�̺���ɱ��\n");

        tell_object(me, HIW "���������ǰ�ľ������������ڵĴ�������ʱ�Ļ����䣬�������������������ȥ��\n\n" NOR);

        message_vision(HIW "$N" HIW "�������е�" + weapon->name() + HIW "���Լ�������ȥ��\n" NOR, me);
        message_vision("ͻȻһ��������Ӱ�ӣ������ֵ�������������$N"
                                   "��ǰ���˹�ȥ��˲�����" + weapon->name() + "����ʧ������\n", me);

        weapon->move("/d/wansong/gu5");

        tell_object(me, HIW "��ʱ����һ������ɱ�������б������ᣬҲδȥϸ�롣\n" NOR);
        me->set_temp("mojiao/suicide", 1);
        return 1;
}

int do_suicide2(string arg)
{
        object me = this_player();

        if (! me->query_temp("mojiao/suicide"))
                return notify_fail("����Ҫ��ʲô��\n");

        tell_object(me, HIW "���ʱһ��ֻ����ɱ�������������û�б�����ײǽ�������𣿣�\n\n" NOR);

        message_vision(HIW "$N" HIW "�ڿշ���ͷ����Ѩ��ǽ��ֱײ��ȥ��\n" NOR, me);

        message_vision(HIW "ͻȻֻ��һ����������������һ����Ӱ�ɳ۶�����$N" HIW "������ӿ���ס��\n"
                           "ȴ��֪Ϊʱ����$N" HIW "��ͷ���Ѿ�ײ�϶�Ѩ��ǽ�ڣ���ʱ���˹�ȥ��\n" NOR, me);

        tell_room(environment(me), "˵ʱ�٣���ʱ�죬������Ӱ����ͣ����" + me->query("name") +
                                   "���𣬳���Ѩ����˹�ȥ��˲����ʧ������\n", me);

      //  me->unconcious();
        me->move("/d/wansong/gu5");
        me->revive();

        me->delete_temp("mojiao/suicide");
        return 1;
}
