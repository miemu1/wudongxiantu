#include <ansi.h>
inherit ROOM;

string look_door();
void create()
{
        set("short", HIR "�����ڹ�����" NOR);
        set("long", @LONG
ͨ�����࣬�Զ���������������ʨ��ⳡ����ա������������
��ʯ����ޣ�����������������ʮ���Զ�ʮ����������������������
����ʹ���������˴�˵���ɽ硣�ڵ����������£���ʯ�޻�׻�����
��η��˪��ѩ��ǰ��ͨ�������ڹ������Ǳ�һ���޴��ʯ�ţ�door��
��ס�ˣ���ʯ����ȴ�����İ���״���ػ�棨huoju���� ϸ��ʯ����
Χ��ֻ�����ĸ������˹�����Сɽ����
LONG );
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room", 1);
        set("no_clean_up", 1);       
        set("item_desc", ([
               "door"   : (: look_door :),
               "huoju"  : HIR "��Щ��濴������֣��ƺ�������ʲô���أ�\n" NOR,
        ]));

        set("exits", ([
                "north" : __DIR__"maze2/entry",  
        ]));
        set("objects", ([
                "/maze/mausoleum/npc/jiangling": 1,  
                "/maze/mausoleum/npc/qianrenzhang": 1,
                "/maze/mausoleum/npc/bairenzhang": 2,
                "/maze/mausoleum/npc/bingshi": 3,
                "/maze/mausoleum/npc/baozi": 2,
                "/maze/mausoleum/npc/tiger": 2,
                "/maze/mausoleum/npc/lions": 1,
                "/maze/mausoleum/npc/ni": 1,
                "/maze/mausoleum/npc/mammoth": 1,
        ]));
        setup();
}

string look_door()
{
        object ob, me;
        int n;
        string opened, msg, temp;

        mapping change_num = ([
               "1" : "һ",
               "2" : "��",
               "3" : "��",
               "4" : "��",
               "5" : "��",
               "6" : "��",
        ]);
        
        me = this_player();
        ob = FUBEN_D->query_maze_mainobj(me);

        if (! objectp(ob))
               return "TSR �������������ʦ��ϵ��\n";

        opened = ob->query("lock/opened");

        if (opened == "" || ! stringp(opened))
               return "ֻ��ʯ�Ž��գ���������İѻ�棨huoju��������Ϩ���ˣ�\n";

        if (ob->query("lock/unlocked") && sizeof(opened) == 4)
               return NOR + WHT "\nֻ��ʯ��������£��İѻ���յ�������һ�����¶�˳�����\n" NOR;

        msg = HIC "ֻ��ʯ�Ž��գ���";
        for (n = 0; n < sizeof(opened); n ++)
        {
              temp = opened[n..n];
              msg += change_num[temp];
              if (n < sizeof(opened) - 1)msg += "��" ;              
        }
        msg += "�ѻ��ȼ���ţ�\n" NOR;
 
        return msg;

}
