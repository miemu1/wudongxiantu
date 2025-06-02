#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
        // �Թ��������̳е�����ĵ������ơ�
        set_inherit_room( ROOM );

        set_lonely_create(1);
        // �Թ�����Ҫ����͵ȼ���

        // �Թ�����Ҫ����ߵȼ���

        // �Թ�������ڵ�ʱ�䡣
        set_remove_time(1800);

        //�Թ�������Ĺ��
        set_maze_npcs(__DIR__"npc/beast");

        // �Թ��еĹ�����ֿ�����
        set_npcs_rate(50);

        //�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/dragon");

        //�Թ��ĵ��߳�
        set_maze_long(10);

        //��ڷ���(�����ڶ���)
        set_entry_dir("north");

        //�������������ӷ���
        set_link_entry_dir("north");

        //�������������ӵ�����
        set_link_entry_room("/d/xiakedao/haibin");

        //��������������ӷ���
        set_link_exit_dir("south");

        //��������������ӵ�����
        set_link_exit_room("/d/xiakedao/haibin");

        //��ڷ��������
        set_entry_short("�����Թ�");

        //��ڷ�������
        set_entry_desc(@LONG
����ˮɫ��Ļ�����������Χ�ѿ���������ˡ�ż�а���Ϯ������
��������������Ĵ�����Щ�߸ߵĺ��ݣ����������ͷ���ڵ�һ˿
��âҲû���ˡ�
LONG
);

        //BOSS���������
        set_exit_short("��֮��");

        //BOSS��������
        set_exit_desc(HIB"

������Ǻ��ľ�ͷ�ˡ�����������
"NOR);

        //�Թ�����Ķ�����
        set_maze_room_short("�����Թ�");

        //�Թ����������������ж�������������ÿ����
        //���ʱ���������ѡ��һ����
        set_maze_room_desc(@LONG
����ˮɫ��Ļ�����������Χ�ѿ���������ˡ�ż�а���Ϯ������
��������������Ĵ�����Щ�߸ߵĺ��ݣ����������ͷ���ڵ�һ˿
��âҲû���ˡ�
LONG
);

        //�������������
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);
        
        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        //set_outdoors(1);
}


