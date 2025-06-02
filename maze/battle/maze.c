// This program is a part of NT MudLIB
// zhanchang.c ս��

inherit VRM_SERVER;

void create()
{
        // �Թ��������̳е�����ĵ������ơ�
        set_inherit_room( ROOM );

        set_lonely_create(1);

        //�Թ�������Ĺ��
        set_maze_npcs( ([
                "/maze/battle/npc/fiend" : range_random(1, 2),
                "/maze/battle/npc/minotaur" : range_random(3, 6),
        ]) );

        //�Թ��ĵ��߳�
        set_maze_long(10);

        set_maze_traps(4);

        //��ڷ���(�����ڶ���)
        set_entry_dir("east");

        //�������������ӷ���
        set_link_entry_dir("west");

        //�������������ӵ�����
        set_link_entry_room(__DIR__"enter1");

        //��������������ӷ���
        set_link_exit_dir("west");

        //��������������ӵ�����
        set_link_exit_room(__DIR__"enter2");

        //��ڷ��������
        set_entry_short("��Ұ");

        //��ڷ�������
        set_entry_desc(@LONG
�����Ǿ�˵�����Ϲ�ʱ�������ս����ַ���ഫԶ��ʱ��
�����Ĵ�����Ϸ��ĵĴ���Ϊ���������׵�Ȩ���������ﱬ��
��һ�����ҵĴ�ս����������Ѿ��ưܲ������Ӳݴ����Ļ�Ұ
֮���ˣ���С�ľͿ�����ʧ������.
LONG);

        //���ڷ��������
        set_exit_short("��Ұ");

        //���ڷ�������
        set_exit_desc(@LONG
����ǰһ������������˿��������������ǳ����ˡ�����С��
���������ͷ紵�����ֵ�ɳɳ����֯�������Ĵ���Ȼ�����ɡ�
LONG
);

        //�Թ�����Ķ�����
        set_maze_room_short("��ս��");

        //�Թ����������������ж�������������ÿ����
        //���ʱ���������ѡ��һ����
        set_maze_room_desc(@LONG
����Խ��Խ���ˣ��㵨���ľ�����ǰ�����ţ�������һЩ
��·�˵�ʬ������á���ʱ����һ�������˺�,������ʲô
�����ڰ��п����ţ��㲻�ɵļӿ��˽Ų���
LONG
);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        set_outdoors(1);
}



