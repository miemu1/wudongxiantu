#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�����Ǳ��𵺼�̳�ڵ�һ���ܵ������ĳ���������ײ�
֪��ͨ��δ����ܵ��ڵƹ�谵���������󣬲�ʱ���������
Ц����ż��������һ������֪�������޵Ŀݹǣ�����ȫ��ֱ��
��Ƥ����鼱֮��ֻ���Ĵ�Ѱ·(xunlu)������û�µĳ�·��
LONG);
        set("no_sleep_room",1);
        set("objects", ([
                "/clone/dream_npc/shenlongdao/xixue-bianfu" : 6+random(8),
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        object me = this_player();
        add_action("do_wang", "xunlu");
        me->start_busy(2 + random(3));

        if (random(2))
        {
                tell_object(me, HIC "�㲻С�Ĳȵ�һ���ݹǣ���Ȼ�����쳣����\n" NOR);
        }
        else
        {
                tell_object(me, HIC "ͻȻһȺ��Ѫ����ɹ�������æӦ�� ����\n" NOR);
        }
}

int do_wang()
{
        object ob = this_player();

        message_vision(HIC "\n$N" HIC "�Ĵ��Ҵܣ�Ѱ���µĳ�·���ƺ�����Զ�����һ˿������\n"NOR, ob);

        switch (random(4))
        {
        case 0 : set("exits/east", __DIR__"st1"); break;
        case 1 : set("exits/east", __DIR__"st2"); break;
        case 2 : set("exits/east", __DIR__"st1"); break;
        default: set("exits/east", __DIR__"st2");
        }
        switch (random(4))
        {
        case 0 : set("exits/west", __DIR__"st1"); break;
        case 1 : set("exits/west", __DIR__"st1"); break;
        case 2 : set("exits/west", __DIR__"st2"); break;
        default: set("exits/west", __DIR__"st2");
        }
        switch (random(4))
        {
        case 0 : set("exits/south", __DIR__"st2"); break;
        case 1 : set("exits/south", __DIR__"st2"); break;
        case 2 : set("exits/south", __DIR__"st1"); break;
        default: set("exits/south", __DIR__"st1");
        }
        switch (random(4))
        {
        case 0 : set("exits/north", __DIR__"jitaiqian"); break;
        case 1 : set("exits/north", __DIR__"st1"); break;
        case 2 : set("exits/north", __DIR__"st2"); break;
        default: set("exits/north", __DIR__"st1");
        }
        remove_call_out("close_out");
        call_out("close_out", 15);
        return 1;
}

void close_out()
{
        if (query("exits/east"))
                delete("exits/east");

        if (query("exits/west"))
                delete("exits/west");

        if (query("exits/south"))
                delete("exits/south");

        if (query("exits/north"))
                delete("exits/north");
}
