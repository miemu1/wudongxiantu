#include <ansi.h>

inherit VRM_SERVER;

void create()
{
        //�Թ��������̳е�����ĵ������ơ�
        set_inherit_room( ROOM );

        //Ψһ����
        set_unique_room( ({
                "/maze/desert/unique_room/guai_boss_room",
                "/maze/desert/unique_room/guai_boss_room",
                "/maze/desert/unique_room/guai_boss_room",
                "/maze/desert/unique_room/guai_boss_room",
        }) );
        set_center_room("/maze/desert/unique_room/king_boss_room");

        //�Թ�������Ĺ��
        set_maze_npcs( ([
                "/maze/desert/npc/guai": 1 + random(3),
        ]) );

        set_npcs_rate(80);

        set_lonely_create(1);

        set_maze_boxs(5);


        //�Թ��ĵ��߳�
        set_maze_long(8);

        //��ڷ���(�����ڶ���)
        set_entry_dir("north");

        //�������������ӷ���
        set_link_entry_dir("north");

        //�������������ӵ�����
        set_link_entry_room("/d/luoyang/wenmiao");

        //��������������ӷ���
        set_link_exit_dir("south");

        //��������������ӵ�����
        set_link_exit_room(__DIR__"out");


        //��ͨ��������
        set_maze_room_short(RED "�޾���Į" NOR);

        set_maze_room_desc(@LONG
һ���޼ʵĴ�Į�����ա���ɳ���ຮ�����ȣ���ʱ������ĥ��ÿ
һ���ˣ�����������û����ˮ�����п��ܾͻᱻɹ����ɳ�ӹ��̣�
���԰ѽ����ã�һ�����ϣ�ȴ�ֱ����͸�ǡ�
LONG);

        //��ڷ��������
        set_entry_short(HIR "�޾���Į���" NOR);

        //��ڷ�������
        set_entry_desc(@LONG
һ���޼ʵĴ�Į�����ա���ɳ���ຮ�����ȣ���ʱ������ĥ��ÿ
һ���ˣ�����������û����ˮ�����п��ܾͻᱻɹ����ɳ�ӹ��̣�
���԰ѽ����ã�һ�����ϣ�ȴ�ֱ����͸�ǡ�
LONG);

        //���ڷ��������
        set_exit_short(WHT "�޾���Į����" NOR);

        //���ڷ�������
        set_exit_desc(@LONG
һ���޼ʵĴ�Į�����ա���ɳ���ຮ�����ȣ���ʱ������ĥ��ÿ
һ���ˣ�����������û����ˮ�����п��ܾͻᱻɹ����ɳ�ӹ��̣�
���԰ѽ����ã�һ�����ϣ�ȴ�ֱ����͸�ǡ�
LONG);
        set_outdoors(1);
}
