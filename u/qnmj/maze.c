#include <ansi.h>
inherit VRM_SERVER;

#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

string *unique_rooms = ({
});

void create()
{
        //�Թ��������̳е�����ĵ������ơ�
        set_inherit_room( ROOM );

        //Ψһ����
        set_unique_room( unique_rooms ); 

        //�Թ�������Ĺ��
        set_maze_npcs( ([
                "/d/maze/qnmj/npc/1": 5,
        ]) );

        //��������
        //set_true_death_room(1);

        //�Թ��ĵ��߳�
        set_maze_long(4);

        //��ڷ���(�����ڶ���)
        set_entry_dir("east");

        //�������������ӷ���
        set_link_entry_dir("east");

        //�������������ӵ�����
        set_link_entry_room(__DIR__"enter");

        //��������������ӷ���
        set_link_exit_dir("west");

        //��������������ӵ�����
        set_link_exit_room(__DIR__"out");

        //�������������
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);

        //��ͨ��������
        set_maze_room_short(HIG"����Ǳ��"NOR);

        set_maze_room_desc(@LONG
�����ǳ���Ǳ�ܡ�
LONG);

        //��ڷ��������
        set_entry_short(HIR"����Ǳ��"NOR);

        //��ڷ�������
        set_entry_desc(@LONG
�����ǿ������ڡ�
LONG);

        //���ڷ��������
        set_exit_short(HIY"ԭʼɭ�ֳ���"NOR);

        //���ڷ�������
        set_exit_desc(@LONG
�����Ǿ���֮����һ��ռ�.��
LONG);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        set_outdoors(1);

        // �Թ������Ƿ�ˢ����ˢ��ʱ������
        set_maze_refresh(3600);
}

string query_my_map(){  return read_file(__DIR__"maze.map");}

