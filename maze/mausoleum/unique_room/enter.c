
#include <command.h>
inherit ROOM;

void create()
{
        set("short", "�ڹ�ͨ��");
        set("long", @LONG
ͨ�����࣬�Զ���������������ʨ��ⳡ����ա������������
��ʯ����ޣ�����������������ʮ���Զ�ʮ����������������������
����ʹ���������˴�˵���ɽ硣�ڵ����������£���ʯ�޻�׻�����
��η��˪��ѩ��
LONG );
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room", 1);
        set("no_clean_up", 1);       
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

void init()
{
        object me;
        string file;
        
        if( !interactive(me = this_player()) || 
            query("init_exits") ) return; 
        
        file = FUBEN_D->query_maze_dir(me); 

        set("exits/northdown", file+"northgate");
        set("exits/southdown", file+"southgate");
        set("exits/westdown",  file+"westgate");
        set("exits/eastdown",  file+"eastgate");
        set("init_exits", 1);
        tell_room(this_object(), "ͻȻ����һ����ת����һ�а����������㷢�ֵذ��³��ּ������ڡ�\n");
        LOOK_CMD->look_room(me, this_object(), me->query("env/brief")); 
        return;
}

