#include <ansi.h>
inherit "/adm/daemons/vrm_server2.c";
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

string *unique_rooms = ({
        "/maze/forestnew/unique_room/snakehole",
        "/maze/forestnew/unique_room/bearlair",
        "/maze/forestnew/unique_room/wolfcave",
        "/maze/forestnew/unique_room/tigerhill",
        "/maze/forestnew/unique_room/dragonland",
});

void create() 
{ 
        //�Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM ); 
                        
        //Ψһ����
        set_unique_room( unique_rooms ); 

        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                /*
                "/maze/forestnew/npc/toad": !random(5), 
                ""/maze/forestnew/npc/rabbit": !random(5),  
                "/maze/forestnew/npc/wolf_baby": !random(5), 
                "/maze/forestnew/wolf_big": !random(5), 
                "/"/maze/forestnew/npc/snake_baby": !random(5), 
                "/maze/forestnew/npc/snake_big": !random(5), 
                "/maze/forestnew/npc/tiger_baby": !random(5), 
                "/maze/forestnew/npc/tiger_big": !random(5), 
                "/maze/forestnew/npc/bear_baby": !random(5), 
                "/maze/forestnew/npc/bear_big": !random(5), 
                "/maze/forestnew/npc/dragon_baby": !random(10), 
                */
                "/maze/forestnew/npc/tiger_king": !random(5), 
                "/maze/forestnew/npc/wolf_king": !random(5), 
                "/maze/forestnew/npc/bear_king": 1, 
                "/maze/forestnew/npc/snake_king": !random(5), 
        ]) );                   

        set_lonely_create(1);

        //�Թ��ĵ��߳� 
        set_maze_long(8); 
        
        //��������
        set_maze_nodeath(1);
                        
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
        set_maze_room_short(HIG"ԭʼɭ��"NOR);
                        
        set_maze_room_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG); 

        //��ڷ�������� 
        set_entry_short(HIR"ԭʼɭ�����"NOR); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);
                        
        //���ڷ�������� 
        set_exit_short(HIY"ԭʼɭ�ֳ���"NOR); 
                        
        //���ڷ������� 
        set_exit_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿 
        set_outdoors(1);                                                

        // �Թ������Ƿ�ˢ����ˢ��ʱ������
        //set_maze_refresh(180);
        
        // �Թ�������߽���ȼ�
        set_remove_time(1800); 
} 


