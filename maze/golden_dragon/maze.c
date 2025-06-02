
#include <ansi.h>
inherit VRM_SERVER;

void create()
{
        // �Թ��������̳е�����ĵ������ơ�
        set_inherit_room( ROOM );

        // �Թ�����Ҫ����͵ȼ���
        //set_enter_min_level(10);

        // �Թ�����Ҫ����ߵȼ���
        //set_enter_max_level(20);

        set_lonely_create(1);

        // �Թ�����ʱ��ID��ˢ��ʱ�䡣
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
        set_entry_dir("south");

        //�������������ӷ���
        set_link_entry_dir("south");

        //�������������ӵ�����
        set_link_entry_room("/d/dragon/spiritgate");

        //��������������ӷ���
        set_link_exit_dir("north");

        //��������������ӵ�����
        set_link_exit_room("/d/dragon/spiritgate");

        //��ڷ��������
        set_entry_short("����԰");

        //��ڷ�������
        set_entry_desc(@LONG
������ǹ��������԰����Χ��ɭɭ�ģ�ֻ���ĸ��ں����Ķ��ڣ�
Ҳ��֪ͨ��δ���
LONG
);

        //BOSS���������
        set_exit_short("ɳ֮��");

        //BOSS��������
        set_exit_desc(HIY"

�������ɳĮ��ͷ������������
"NOR);

        //�Թ�����Ķ�����
        set_maze_room_short("����԰");

        //�Թ����������������ж�������������ÿ����
        //���ʱ���������ѡ��һ����
        set_maze_room_desc(@LONG
������ǹ��������԰����Χ��ɭɭ�ģ�ֻ���ĸ��ں����Ķ��ڣ�
Ҳ��֪ͨ��δ���
LONG
);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        //set_outdoors(1);
}

