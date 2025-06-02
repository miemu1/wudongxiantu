
#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <localtime.h>
#include <getconfig.h>

#define WARRING           2
#define THEEND            0
#define WAIT_START        3
#define XYNPC            "/kungfu/class/generate/xiangyang/"
#define GIFT_EXP_BASE    10000         
#define GIFT_POT_BASE    10000
#define GIFT_MAR_BASE    3000
#define GIFT_WEI_BASE    10000
#define GIFT_YUE_BASE    10000 
#define DB_D             "/adm/daemons/dbd"

#define MEMBER_D         "/adm/daemons/memberd"

// ��а���������ϵۣ���ؤ�������Ԯ
#define DONGXIE          "/kungfu/class/generate/xiangyang/huang"
#define XIDU             "/kungfu/class/generate/xiangyang/ouyangfeng"
#define NANDI            "/kungfu/class/generate/xiangyang/yideng"
#define BEIGAI           "/kungfu/class/generate/xiangyang/hong"

// �����С��Ů
#define YANGGUO          "/kungfu/class/generate/xiangyang/yang"
#define LONGNV           "/kungfu/class/generate/xiangyang/longnv"

// ���ӵ��ɹű�
#define MORE_SOLDIER     10
// ���������ؾ����
#define MOVE_WAIT        60

// ���ӵ�����ʿ������
#define ADD_XY_SOLDIER   120

// �����ɹű�����
#define ADD_MGB_TIMES    3

// �����ɹű�ʱ����
#define ADD_MGB_WAIT     120

// ���Ա�־
#define TEST             0

// �Ƿ������ű�־
#define ALLOW_START      1

inherit F_DBASE;

int status = 0;                // ����ս״̬
int start_status = 0;          // ϵͳ״̬��1 ������ʼ�������ظ�����
int sign_up_status = 0;        // ������־
string *p = ({});             // �μ�����ս���������б�

int start_time = 0;           // ��������ս��ʼʱ��
int attack_time = 0;          // �ɹ��˿�ʼ����ʱ��
        
int tiemuzhen = 0;            // �����Ƿ������ľ��

int n_mg_tq = 0, n_mg_zb = 0, n_mg_gb = 0 , n_mg_bb = 0;// ������ܱ𡢹�������������
int n_xy_sb = 0; // ����ʿ��

int n_xy_sb2; // ����ʿ���������
int n_mg_sb2; // �ɹ�ʿ���������

int add_mgb_times = 0; // ��Ԯ�ɹű�����
int query_add_mgb_times(){return add_mgb_times;}

int last_add_mgb_time = 0; // �ϴ���Ԯ�ɹű�ʱ��
int last_combat_change_time = 0; // �ϴε���ս����ʱ��
int add_xyb_flag = 0; // ��������ʿ����־

public int query_add_xyb_flag(){return add_xyb_flag;}

// ������ʿ��Ԯ����Ϣ
string xy_msg1 = "----";
string query_xy_msg1(){return xy_msg1;}

// 1 Ϊ����  2 Ϊ�ɹ�
int who_win; // ��������ս˭ʤ��

// ��������ս���к� RAN_NUM
// �����к���ÿ�ο�ʼǰ��������������Ǳ�ע������������ս����Ψһ��
// ÿɱ��һ���ɹŲ��������� /xywar/RAN_NUM/point, point����ɱ�����ɹű��ȼ�������
int RAN_NUM = 0;

public int get_who_win(){return who_win;}
public int set_who_win(int who){who_win = who;} 
public void player_die(string id);
public int get_ran_num(){return RAN_NUM;} // ��ȡ������������ս���к�

object xy_guojing; // ����
int guojing_moved = 0; // �����Ƿ��Ѿ����ɹ��˽�ս

// �����ɹ�Ԯ�����ڷ�λ������������������ʦ��̬���ƣ�
string yb_attack_where = "none";
string query_yb_attack_where() { return yb_attack_where; }
string set_yb_attack_where(string str_where) { return yb_attack_where = str_where; }


// /kungfu/class/generate/xiangyang/guo.c ����
public int if_guojing_moved()
{
        return guojing_moved;
}

// ��������
int die_xywar(object me)
{
        me->delete_override("die");

        // ����ս�Ѿ�������û����������
        if (status == THEEND)return 0;
        
        me->move("d/city/wumiao");

        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("eff_qi"));
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("eff_jing"));
        me->set("jingli", me->query("max_jingli"));        

        me->revive();
        tell_object(me, BLINK + HIG "���Ѿ��˳���������ս��\n" NOR);
        player_die(me->query("id"));
        
        me->save();
        
        return 1;        
}

// �ƶ�NPC���ɹž�Ӫǰ�Ծ�Ӫ����PLAYER������
void clear_junying()
{
        object room;
        object *ob;
        int i, j;
        
        for (i = 1; i < 4; i ++)
        {
                if (! objectp(room = find_object("/d/xiangyang/junying" + sprintf("%d", i))))
                        room = load_object("/d/xiangyang/junying" + sprintf("%d", i));
                
                if (! objectp(room))
                {
                        log_file("xywar_clear_junying", "junying" + sprintf("%d", i) + " load object fail.\n");
                        return;
                }

                ob = all_inventory(room);        
                
                if (! sizeof(ob))continue;
                
                // ���ھ�Ӫ����������ƶ�������
                for (j = 0; j < sizeof(ob); j ++)
                {
                        if (playerp(ob[j]))
                        {
                                ob[j]->move("/d/city/wumiao");
                                continue;
                        }                        
                }                        
        }                                                        
        
        XYWAR_D->xywar_message(HIW "�ɹž�Ӫ������ϣ�\n" NOR);
}

// ���ñ����μ���������ս������������
void set_no_die(object me)
{
        me->set_override("die", (: call_other, __FILE__, "die_xywar", me:));

        return;
}


int is_guojing_died = 0;     // �����Ƿ�����

string xysb_poision = "������������";

void start_xywar();                // ����ս��ʼ
void reset_data();                 // ����ս������������������
string xywar_message(string msg);  // ����ս��
void set_now_status(int flag);     // ����ս��״̬

void combat_xjtuibing();          // ս��������˱�
void combat_sdjixi();             // ս������������

string more_soldier_poision;  // ĳһ������ʿ����MORE_SOLDIER��

string player_leader; // ��ҽ����ID

int last_move_xysolder = 0; // �ϴε��������ؾ���ʱ��
int query_last_move_xysolder(){ return last_move_xysolder;}

// �Ĵ���פ���ص�
mapping doors = ([
        "west"  :      "/d/xiangyang/guandao_1",
        "east"  :      "/d/zhongzhou/toyy",
        "south" :      "/d/xiangyang/caodi6",
        "north" :      "/d/xiangyang/caodi3",
]);

mapping doors_name = ([
        "west"  :      "�׻���",
        "east"  :      "������",
        "south" :      "��ȸ��",
        "north" :      "������",
]);

string random_doors_name()
{
        string *keys_name;
        
        keys_name = keys(doors_name);
        
        return doors_name[keys_name[random(sizeof(keys_name))]];
}

// /kungfu/class/generate/xiangyang/guo.c random_move()����
public mixed get_doors()
{
        return doors;
}

// ����ʿ���Ĵ���פ���ص�
mapping doors2 = ([
        "west"  :      "/d/xiangyang/westgate1",
        "east"  :      "/d/xiangyang/eastgate1",
        "south" :      "/d/xiangyang/southgate1",
        "north" :      "/d/xiangyang/northgate1",
]);
              
mapping doors2_name = ([
        "west"  :      "�׻�����",
        "east"  :      "��������",
        "south" :      "��ȸ����",
        "north" :      "��������",        
]);
       
// ������ӽ�����㳡���ĸ��ص�
mapping doors3 = ([
        "west"  :      "/d/xiangyang/westjie1",
        "east"  :      "/d/xiangyang/eastjie1",
        "south" :      "/d/xiangyang/southjie1",
        "north" :      "/d/xiangyang/anfupailou",
]);

mapping doors3_name = ([
        "west"  :      "�����������",
        "east"  :      "�����Ƕ����",
        "south" :      "�������ϴ��",
        "north" :      "��������¥",        
]);

// �Ĵ��ŵı�������
// ({ ����ܱ𡢹����� ����  })
mapping n_soldier = ([
        "west"  :      ({0, 0, 0, 0}),
        "east"  :      ({0, 0, 0, 0}),
        "south" :      ({0, 0, 0, 0}),
        "north" :      ({0, 0, 0, 0}),
]);

// ��������
public string re_poision(string p)
{
        if (! sizeof(p))return "";
        
        switch(p)
        {
                case "west":
                        return "east";
                case "east":
                        return "west";
                case "north":
                        return "south";
                default:
                        return "north";                                                
        }
}

// ����ս����
void xywar_over()
{
        status = THEEND;
        xywar_message(HIR "��ʾ��������������ս���ڱ����������㣬���������\n" NOR);
        reset_data();           // ����ս������������������

        return;
}

// ����սʧ��
// �ɹ�ʤ��
public void war_fail()
{        
        who_win = 2;;
        
        call_out("xywar_message", 4, HIY "������������ս�Բа��ճ����ɹ��˳���ֱ�룬ռ�����������Ӵ�����Ϳ̿�������� ������\n");
        call_out("xywar_message", 5, HIY "�������Ǵβ��ҵ���������ս����ʿ��ȴ��Զ���ᱻ������������\n");

        set_now_status(THEEND);

        return;
}

// �������в�ս���
void gift_to_player()
{
        object dob;
        int i, n;
        string str_ran_num;
        
        
        n = sizeof(p);
        
        // ��������������ս���к�ת��Ϊ�ִ�
        str_ran_num = sprintf("%d", RAN_NUM);
        
        for (i = 0; i < n; i ++)
        {
                dob = find_player(p[i]);
                
                if (! objectp(dob))continue;
                
                // ���ù�ѫ
                dob->add("xywar/win", 1);

                // ����ս����ɱ�����������н�����һ��δɱ��������Ϊ���
                if (dob->query("xywar/xy_" + str_ran_num))
                {
                        GIFT_D->delay_bonus(dob,
                                        ([ "exp"      : GIFT_EXP_BASE + dob->query("xywar/xy_" + str_ran_num),
                                           "pot"      : GIFT_POT_BASE + dob->query("xywar/xy_" + str_ran_num) / 2,
                                           "weiwang"  : GIFT_WEI_BASE + dob->query("xywar/xy_" + str_ran_num) / 20,
                                           "score"    : GIFT_YUE_BASE + dob->query("xywar/xy_" + str_ran_num) / 20,
                                           "mar"      : GIFT_MAR_BASE + dob->query("xywar/xy_" + str_ran_num) / 20,
                                           "prompt"   : "������������սʤ����"]), 999);
                        dob->delete("xywar/xy_" + str_ran_num);
                }
                else
                {
                        GIFT_D->delay_bonus(dob,
                                        ([ "exp"      : GIFT_EXP_BASE,
                                           "pot"      : GIFT_POT_BASE,
                                           "weiwang"  : GIFT_WEI_BASE,
                                           "score"    : GIFT_YUE_BASE,
                                           "mar"      : GIFT_MAR_BASE,
                                           "prompt"   : "������������սʤ����"]), 999);                                         
                }
                dob->save();

                /*
                // ������Ϊ�����ֽ���
                if (dob->query("combat_exp") >= 30000000)
                        GIFT_D->delay_bonus(dob,
                                        ([ "exp"      : GIFT_EXP_BASE + random(GIFT_EXP_BASE / 2),                                           
                                           "pot"      : GIFT_POT_BASE + random(GIFT_POT_BASE / 2),                                       
                                           "weiwang"  : GIFT_WEI_BASE + random(GIFT_WEI_BASE / 2),                               
                                           "score"    : GIFT_YUE_BASE + random(GIFT_YUE_BASE / 2),  
                                           "mar"      : GIFT_MAR_BASE + random(GIFT_MAR_BASE / 2),                           
                                           "prompt"   : "������������սʤ����"]), 999);
                else
                        GIFT_D->delay_bonus(dob,                                              
                                        ([ "exp"      : GIFT_EXP_BASE / 2 + random(GIFT_EXP_BASE / 3),                                           
                                           "pot"      : GIFT_POT_BASE / 2 + random(GIFT_POT_BASE / 3),                                       
                                           "weiwang"  : GIFT_WEI_BASE / 2 + random(GIFT_WEI_BASE / 3),                               
                                           "score"    : GIFT_YUE_BASE / 2 + random(GIFT_YUE_BASE / 3),  
                                           "mar"      : GIFT_MAR_BASE / 2 + random(GIFT_MAR_BASE / 3),                           
                                           "prompt"   : "������������սʤ����"]), 999);                                                           
         */
        }
        
}

// ����սʤ��
// ����ʤ��
// �������в�ս���
public void war_win()
{
        who_win = 1;
        
        gift_to_player();
        
        set_now_status(THEEND);
        
        call_out("xywar_message", 4, HIW "���������ؾ�����ҵط����ֿ������ڻ������ɹž�����������սʤ����\n");

        return;
}

// �ɹ���ռ������㳡
void arrived_center()
{
        if (status == THEEND)return;

        war_fail();

        xywar_message(HIR "�ɹ�����ռ����������㳡��������������ս������ʧ�ݸ��գ�\n" NOR);                
        
}

// ���ڱ������ʣ�಻��������ս��ʧ��
void war_end_player()
{
        if (status == THEEND)return;
                
        xywar_message(HIR "���ڲ�����������ս�������ʣ�಻�����������Լ����ֿ��ɹ��˵Ĺ��ơ�" NOR);
        xywar_message(HIR "�ɹ��˳���ֱ�룬ռ�����������Ӵ�����Ϳ̿�������� ����" NOR);
        xywar_message(HIR "�������Ǵβ��ҵ���������ս����ʿ��ȴ��Զ���ᱻ������������\n" NOR);
        
        set_now_status(THEEND);
                
}

// �ⲿ���� /kungfu/class/generate/xiangyang/xyshibing.c����
// �ж�Ŀǰ�Ƿ��ܵ�����
public int is_moved()
{
        if (xysb_poision == "������������")return 0;
        
        return 1;
}

// ����ʿ��Ŀǰ��λ��
// �ⲿ�ɵ���
public string xy_soldier_poision(string para)
{
        if (xysb_poision == "������������")
                return xysb_poision;

        switch(para)
        {
                // ���ص���
                case "name" :
                        return doors3_name[xysb_poision];
                
                // ���ط�λ
                case "poision" :
                        return xysb_poision;
                
                case "env" :
                        return doors3[xysb_poision];

                default:return "error";                                                
        }
}

// �ɹž�������
int total_menggu_soldier(string route)
{
        int i, j, total = 0;
        string *key_n_soldier;
        int *route_n_soldier;

        key_n_soldier = keys(n_soldier);

        // ��������ʿ������
        if (route == "xiangyang")
        {
                return n_xy_sb;
        }
        
        // �����ɹ�ʿ������
        if (route == "total")
        {
                for (j = 0; j < sizeof(key_n_soldier); j ++ )
                {
                        for (i = 0; i < sizeof(n_soldier[key_n_soldier[j]]); i ++)
                        {
                                total = total + n_soldier[key_n_soldier[j]][i];
                        }
                }

                return total;
        }
        
        // ĳһ�ƶ������ϵ��ɹž�������
        if (stringp(route))
        {
                route_n_soldier = n_soldier[route];

                if (sizeof(route_n_soldier))
                {
                        for (i = 0; i < sizeof(route_n_soldier); i ++ )
                        {
                                total = total + route_n_soldier[i];
                        }
                }

                return total;
        }
}

// key = "max" || key = "min"
// ����n_soldier ��ʿ��������ǿ����������
// ����ʿ�� ����Ϊ1������Ϊ2, �ܱ�Ϊ3�����Ϊ4
string max_min_n_soldier(string keys)
{
        int i, j, power_w, power_e, power_s, power_n;
        int max_tmp1, max_tmp2, min_tmp1, min_tmp2;
        int max_result, min_result;
        string smax_tmp1, smax_tmp2, smin_tmp1, smin_tmp2;
        string smax_result, smin_result;
        string key_n_soldier;

        if (keys != "max" && keys != "min")return "NULL";

        power_w = 0;
        for (i = 0; i < 4; i ++)
        {
                power_w = power_w + n_soldier["west"][i];
        }
        power_e = 0;
        for (i = 0; i < 4; i ++)
        {
                power_e = power_e + n_soldier["east"][i];
        }
        power_n = 0;
        for (i = 0; i < 4; i ++)
        {
                power_n = power_n + n_soldier["north"][i];
        }
        power_s = 0;
        for (i = 0; i < 4; i ++)
        {
                power_s = power_s + n_soldier["south"][i];
        }

        max_tmp1 = power_w >= power_e ? power_w : power_e;
        smax_tmp1 = power_w >= power_e ? "west" : "east";
        max_tmp2 = power_n >= power_s ? power_n : power_s;
        smax_tmp2 = power_n >= power_s ? "north" : "south";
        
        min_tmp1 = power_w <= power_e ? power_w : power_e;
        smin_tmp1 = power_w <= power_e ? "west" : "east";
        min_tmp2 = power_n <= power_s ? power_n : power_s;
        smin_tmp2 = power_n <= power_s ? "north" : "south";

        max_result = max_tmp1 >= max_tmp2 ? max_tmp1 : max_tmp2;
        smax_result = max_tmp1 >= max_tmp2 ? smax_tmp1 : smax_tmp2;
        min_result = min_tmp1 <= min_tmp2 ? min_tmp1 : min_tmp2;
        smin_result = min_tmp1 <= min_tmp2 ? smin_tmp1 : smin_tmp2;

        if (keys == "max")
        {
                return smax_result;
        }

        if (keys == "min")
        {
                return smin_result;

        }

}

// �ɹ�ʿ������ͨ�棬����ϵͳ�ж�ÿ���������
// ����ʿ��ͨ�棬����ϵͳ�ж�����ʿ��������
void soldier_die(string route, int which)
{
        if (route == "xiangyang") // ����ʿ������
        {
                n_xy_sb -= 1;
                if (n_xy_sb <= 0)n_xy_sb = 0;
                return;
        }

        // route ����west, east, south, north�е�һ�֣� which �������
        if (route != "west" &&
            route != "north" &&
            route != "south" &&
            route != "east")return;

        // 0 ���������1�����ܱ�2��������3������
        if (which < 0 || which > 3)return;
        
        // ��ROUTE��һ��
        route = re_poision(route);
        
        n_soldier[route][which] -= 1;
        


        if (n_soldier[route][which] <= 0)n_soldier[route][which] = 0;

        return;
}

// �жϹ����Ƿ��Ѿ�����
int is_guojing_die()
{
        return is_guojing_died;
}

// ��������
// ������������������ʿ���Զ�����
void guojing_die()
{
        is_guojing_died = 1; // ��־����������
}

// �����μ�����ս
void sign_up(string id)
{
        if (! sizeof(p)) p = ({});

        p += ({ id });

        return;
}


// �����ѱ���������
public int n_sign_up(){return sizeof(p);}

// ���ر���������
public string *p_sign_up(){return p;}

// ���ĳID�Ƿ���״̬��Ȼ��Ч
int if_sign_up(string id)
{
        if (! sizeof(p))return 0;

        if (member_array(id, p) != -1)return 1;

        return 0;
}

// �ⲿ���ã�������������������վ������ɾ��
public void player_die(string id)
{
        if (! stringp(id))return;
        if (! if_sign_up(id))return;
        
        p -= ({ id });
        
        return;
}

// ������ߵı�����Ҳ�ɾ��֮
void sub_check_player()
{
        int i;
        for (i = 0; i < sizeof(p); i ++ )
        {
                if (! objectp(find_player(p[i])))
                {
                        p -= ({ p[i] });
                        return sub_check_player();
                }
        }
        
        if (sizeof(p) < 5 && status == WARRING && ! TEST)war_end_player();
        
}

// ������ߵı�����Ҳ�ɾ��֮
// ���� sub_check_player()ִ��
void check_player()
{
        int i;
        remove_call_out("check_player");
        call_out("check_player", 10); // ���μ�����ս�����

        if (! sizeof(p))return;

        sub_check_player();

        return;
}

// ���ظ���״̬
// 1=����ʤ�� | -1=�ɹ�ʤ��
// 2=������   | 0=������δ��ʼ
// 3=�ȴ�����
int now_status(){return status;}

// ���ø���״̬
void set_now_status(int flag)
{
        // ���״̬Ϊ����ս��
        if (flag == THEEND)
        {
                status = THEEND;
                call_out("xywar_message", 10, HIG "������������ս�ѽ�����ϵͳ����1�������ͷ���Դ�������ָ�ƽ����");
                reset_data(); // ��ʼ����������
        }

        status = flag;
}

// ������־��1=���Ա���  0=�����Ա���
int sign_up_status(){return sign_up_status;}

// ���ñ�����־
void set_sign_up_status(int flag){sign_up_status = flag;}

// �˱���־
int dest_status()
{
        if (status == THEEND)
        {
                return 1;
        }

        return 0;
}

// ���˲����ܹ�����Ϣ����
int filter_listener(object ob)
{
            // �ƻ��в�����
        if (ob->query("doing") == "scheme") return 0;
        return 1;
}

// ����սϵͳͨ��
void xywar_message(string msg)
{
        string prompt;
        object *listeners;

        prompt = HIY "������ս����" NOR;
        listeners = filter_array(users(), (: filter_listener :));
        message( "story",  prompt + HIC + msg + "\n" NOR, listeners );
}

void do_attack_msg(string msg)
{
        if (status == THEEND)return;
        
        xywar_message(msg);
}

// ����ͨ�棺����û�б�������
int filter_listener2(object ob)
{
        if (member_array(ob->query("id"), p) == -1)return 0;

        return 1;
}

// ����ͨ��
void guojing_message(string msg)
{
        string prompt;
        object *listeners;

        prompt = HIY "��������" NOR;
        listeners = filter_array(users(), (: filter_listener2 :));
        message( "story",  prompt + HIR + msg + "\n" NOR, listeners );
}

// ÿ��1�պ�15������8��30��ʼ
void check_time()
{
        string *str_bjtime,bjtime1;
        
        remove_call_out("check_time");
        call_out("check_time", 15);

        // �������ս����ʼ��־
        if (start_status)return;

        // 1Сʱ�ڲ����ظ��Զ�����
        if (time() - DB_D->query_data("xywar/last_auto_start") < 36000)
                return;
                
        // ����Ƿ�������ʱ�䣬����������ÿ�ʼ��־
        // ���ر���ʱ�� (��:��:��:ʱ:��:��)
        bjtime1 = MEMBER_D->bjtime(time(), 0);
        str_bjtime = explode(bjtime1, ":");
        
        // ÿ��1�գ���15��20��30�ֿ�ʼ
        if (str_bjtime[2] == "1" || str_bjtime[2] == "15")
        {
                if (str_bjtime[3] == "20" && str_bjtime[4] == "30")
                        DB_D->set_data("xywar/start", 1);
        }

        // ��鿪ʼ��־��������
        if (DB_D->query_data("xywar/start"))
        {                
                DB_D->set_data("xywar/start", 0);
                DB_D->set_data("xywar/last_auto_start", time());
                log_file("xywar", "xywar �� " + ctime(time()) + " �Զ�������\n");
                start_xywar();
        }
}

void create()
{
        seteuid(getuid());
        set("channel_id", "����ս��ϵͳ");
        set("no_clean_up", 1);
        CHANNEL_D->do_channel(this_object(), "sys", "ϵͳ�Ѿ�������");
        
        if (! ALLOW_START)return;
        
        remove_call_out("check_time");
        call_out("check_time", 10); // �������ս��ʼʱ��
        remove_call_out("check_player");
        call_out("check_player", 10); // ���μ�����ս�����
        remove_call_out("check_combatd");
        call_out("check_combatd", 30); // ս��ս��ϵͳ�ܿغ���
}

// ս��ս��ϵͳ�ܿ��ļ������ڿ����ɹž���ս�����ӵ���
void check_combatd()
{
                int total, w, e, s, n;
                int xytotal;
                string max_route;
                string dj_name;
                
                remove_call_out("check_combatd");
                call_out("check_combatd", 10);

                // ����ս����
                if (status == THEEND)return;
                
                // ����������������
                total = total_menggu_soldier("total");
                xytotal = total_menggu_soldier("xiangyang");
                w = total_menggu_soldier("west");
                e = total_menggu_soldier("east");
                s = total_menggu_soldier("south");
                n = total_menggu_soldier("north");
                
                // ����ʿ�����˹�����ʾ
                if (xytotal < n_xy_sb2 / 2 && ! guojing_moved)
                {
                        xywar_message(HIW "�ξ�̽�ӣ�������Ŀǰ���ξ��Ѿ����˹��룬���ʮ��Σ����\n" NOR);

                        // 
                        if (! is_guojing_die())
                        {
                                xywar_message(HIW "�������ã���Ȼ��ˣ��ҹ�ĳ�������������� ����" NOR);
                                xywar_message(HIR "��˵���������������ɹ��˾�һ��ս��\n" NOR);
                                
                                call_out("xywar_message", 2, HIY "�ɹŽ��죺�ɹ���ʿ����ǰ�尡���ξ��Ѿ������ɾ��ˡ�\n");

                                // ��guojing �ƶ����ɹ������ĵط�
                                if (objectp(xy_guojing))
                                {
                                        max_route = max_min_n_soldier("max");
                                        xy_guojing->move(doors[max_route]);

                                        // �����ƶ�����
                                        xy_guojing->set("route", re_poision(max_route));

                                        // �Ѿ��ƶ���־
                                        guojing_moved = 1;                                        
                                }
                        }
                }

                // ����ս���У���ʱ����ս��
                /*
                */
                if (status == WARRING || (status == WAIT_START && total_menggu_soldier("total") < 120))
                {
                        // 1.  �ɹž�����������80ʱ�ɱ���Ԯ
                        if (add_mgb_times < ADD_MGB_TIMES &&
                               time() - last_add_mgb_time >= ADD_MGB_WAIT &&
                               (status == WARRING || status == WAIT_START) &&
                               total_menggu_soldier("total") < 120)                        
                        {
                                last_add_mgb_time = time();
                                call_out("xywar_message", 2, HIW "�ɹ�̽�ӣ������ξ��ý�����ʿ֧�֣���ǿ�ֿ����Ҿ�Ŀǰ�������أ�");
                                call_out("xywar_message", 4, HIW "�ɹŽ��조�š���һ��������������Ӧ�ò�ȡһЩ�ж��ˣ���������̡���");
                                call_out("xywar_message", 5, HIY "����̽�ӣ������ɹ����ѷų����̣�����Ԯ������������");
                                call_out("combat_add_soldier", 7);
                                        
                        }
                        
                        // 2.  �ɹž��ӽ���3���Ӻ�ʼ����ս��
                        if (time() - attack_time > 180 && 
                            time() - last_combat_change_time > 90 && // �����ϴ�ս������ʱ��Ϊ90��
                            random(5) == 1)
                        {
                                last_combat_change_time = time();
                                
                                switch(random(5))
                                {
                                        // ����˱�
                                        case 0:
                                                combat_xjtuibing();
                                                break;
                                        // ��������
                                        default :
                                                combat_sdjixi();
                                                break;                                        
                                }
                        }

                        // �ɹ���ȫ��������ʤ��
                        if (total_menggu_soldier("total") <= 0)
                        {
                                xywar_message(HIG "�ɹž��Ѿ�ȫ����û��");
                                war_win();
                                return;
                        }
                        
                        // ����30�������������ʤ��
                        if (time() - attack_time > 1800)
                        {
                                xywar_message(HIG "�����������Ǿ����ڶ���Ҽ���ʿ��Ŭ�����Ѿ����س���30����");
                                xywar_message(HIG "�������ɹ�����������Ѿ����Ĵ�����ֻ����ʱ�˱���");
                                war_win();
                                return;                                
                        }
                }

                // ���ڵȴ�����
                if (status == WAIT_START)
                {
                        if (random(3) == 1)
                        {
                                switch(random(10))
                                {
                                        case 0:
                                                xywar_message("�������ɹ������ڵ�����ӣ��뱣����������ʿ�������׼������ʱ��ս��");
                                                xywar_message("���أ���λ�س��������Է��������׼����ʱӭ���ɹž�����������������\n");
                                                break;
                                        case 1:
                                                xywar_message("�������ɹŵ�ǧ���ڴӾ�ǰ����һ����������ѧ��ʦ�����򲻿����ӡ�");
                                                xywar_message("���������ֻҪ��(guard)ס·�ڣ��ɹ��˱��޷�ͨ�����������ص��ɹ��˻�����������ס·�ڵ���ҡ�");
                                                xywar_message("���أ��ɹ�ǧ�򳤲�����������Ϊ��2�����µ���ң�ͬʱ��Ϊ��2�����µ���Ҽ�ʹ��(guard)ס·��\n"
                                                              "            ��Ҳ�޷�����סǧ�򳤡�\n");
                                                
                                                break;
                                        case 2:
                                                xywar_message("�ɹ�̽�ӣ���������ͻȻ�����˴���������ʿ���������������سǳء�");
                                                if (tiemuzhen)dj_name = "�ɼ�˼��";
                                                else dj_name = "�ɹŽ���";
                                                xywar_message(dj_name + "���ߣ�����������ͬ����˺����һȺ�ں�֮�ڱؽ������Ҽ�֮�¡�\n");                                        
                                                break;                
                                        case 3:
                                                xywar_message("���أ���ս�������ɱ�������ɹ��˺󶼻���һ������Ϊ��Ǳ�ܽ�����");
                                                xywar_message("���أ������������սʤ�������в�ս��ң���������;�˳��ģ�������÷ḻ�Ľ���\n");
                                                break;
                                        case 4:
                                                xywar_message("���أ��ڶԿ��ɹ���ʱϵͳ���Զ��رղ�ս��ҵ�ս����Ϣ����;����򿪣�����Ӱ����Ϸ�ٶȡ�\n");
                                                break;
                                        case 5:
                                                xywar_message("���أ��ɹ��˹�ƶ�ˣ���ս���л���ʱ����ս����Ҳ���ܻ��ɱ���Ԯ��");
                                                xywar_message("���أ���ҽ��������˫��ս��״����ʱ����ս�Ե�����ָ�Ӹ���ս��ҵֿ��ɹ��˽�����\n");                                                
                                                break;
                                        case 6:
                                                xywar_message("��������ҽ�����ڱ�����������ս��ʹ��һ�α�����ʹ�ú������120�������ؾ���");
                                                xywar_message("������ʹ�ñ�����ָ���� " HIY "xy add xyb " HIC "��\n");
                                                break;
                                        case 7:
                                                xywar_message("������һ��������ɹ��˶��棬�ɹ�������Զ���ɱ��������������������ɹ����У���������������\n");
                                                break;
                                        case 8:
                                                if (tiemuzhen)
                                                {
                                                        xywar_message("��������ĳ���׸������ľ��۳Ҵ�Į���乭��񣬲������ȴ��սɳ����");
                                                        xywar_message("�������������ѵ�ͷ���ɹ���ɱ�ӳ��ԣ����չ�ĳ�����������Ҵ��ν�ɽ������������");
                                                        xywar_message("��������ս��ҿ�ѡ����������͵Ϯ�ɹž�Ӫ��ֻҪɱ���ɼ�˼����ľ���ɹ��˱㲻�����ơ�\n");
                                                        break;
                                                }
                                                xywar_message("��������ĳ���׸������ľ��۳Ҵ�Į�����ɹ��ܱ��乭��񣬲������ȴ��սɳ����");
                                                xywar_message("�������������ѵ�ͷ���ɹ���ɱ�ӳ��ԣ����չ�ĳ�����������Ҵ��ν�ɽ������������");
                                                xywar_message("�������ɹ��ܱ����ɹ�����Ϊ�������֡����������׼���мɲ������ӡ�");
                                                xywar_message("�����������������ڼ������Ʊ������ǧ�򳤺�Ӧ����ȫ�����ܱ�����\n");
                                                break;
                                        case 9:
                                                xywar_message("�����������Ѿ�������Ũ�ҵ�����ζ���������Ѹ�����ʰϸ����ʱ׼����������������һƬ���ҡ�");
                                                break;
                                        default:
                                                xywar_message(HIW "�ɹž�ʿ�������Ѽ�����ϣ�������ء���ǹ��ʸ�ѵ�����ϣ���ʱ���Կ�ս��" NOR);
                                                xywar_message(HIY "������ʿ���Ҿ��Ѽ�����ϣ��ĳ��ž�Ҫ���������ر����أ��Ҿ������ɹ����������ס�\n" NOR);
                                                
                                                break;                                                                                                                                
                                }
                        }
                }

                /*
                ս�����ɹž��ӿ���ս���и��������ı�ս��
                1����������
                2������˱�
                3�����ɱ���
                */
}

// ����ս�����������������
void reset_data()
{
            p = ({});                 // �μ�����ս���������б�
        status = THEEND;          // ����ս״̬
        start_status = 0;         // ϵͳ״̬ �ָ���δ��ʼ״̬
        sign_up_status = 0;       // ������־
            tiemuzhen = 0;            // �����Ƿ������ľ��
        n_mg_tq = 0;
        n_mg_zb = 0;
        n_mg_gb = 0;
        n_mg_bb = 0;              // ������ܱ𡢹�������������
        n_xy_sb = 0;              // ����ʿ������        
        is_guojing_died = 0;      // �����Ƿ�������־

        add_mgb_times = 0;             // ��Ԯ�ɹű�����
        add_xyb_flag = 0;              // ��Ԯ����ʿ��������־
        last_add_mgb_time = 0;         // �ϴ���Ԯ�ɹű�ʱ��
        guojing_moved = 0;             // �����Ƿ��Ѿ����ɹ��˽�ս
        xysb_poision = "������������"; // �����ؾ�פ����
        player_leader = "";            // ��ҽ����ID
        last_move_xysolder = 0;        // �ϴε��������ؾ���ʱ��
        start_time = 0;                // ��������ս��ʼʱ��
        attack_time = 0;               // �ɹ��˿�ʼ����ʱ��
        who_win = 0;                   // ˭ʤ��
        xy_msg1 = "----";              // ������Ԯ��Ϣ�������
        yb_attack_where = "none";      // �����ɹű���������

}


// �ɹ��˿�ʼ��������
void do_attack()
{
        if (status == THEEND)return;

        xywar_message(HIR "�ɹ��˿�ʼΧ�������ǣ�" NOR);
        attack_time = time();
        status = WARRING;
}

// �����ɹž�ս��
// ��Լÿ���Ӳ���һ�Σ�ֱ����ʼ����
void do_combatd_message(int i)
{
        string dj_name;
        if (tiemuzhen)
        {
                dj_name = "�ɼ�˼��";
        }
        else
                dj_name = "�ɹŴ�";

        if (status == THEEND)return;
        
        switch(i)
        {
                case 1:
                        xywar_message(dj_name + "�����Һ��ȫ���ڴ���Ӫ������Ӻ�ȫ����ʼΧ�������ǣ�");
                        break;
                // �����ɹ����ܾ���
                case 2:
                        xywar_message("�ξ�̽�ӣ������ɹž���������ԼΪ��" + HIY + sprintf("%d", total_menggu_soldier("total"))  + HIC "���ˣ�������"
                                  "·���ֱ�פ������ȸ�ţ��׻��ţ������ż��������⡣");
                        if (tiemuzhen)
                        {
                                xywar_message(HIR "�ξ�̽�ӣ������ɹž��ɳɼ�˼����ľ���������졣" NOR);
                        }
                        break;
                //
                case 3:
                        xywar_message("�ξ�̽�ӣ����������ξ��ѵ�����ϣ���ʱ׼��ӭ���ɹž���");
                        break;
                //
                case 4:
                        xywar_message("�������뱨���μ���������ս�����������֯����ס�Ĵ���·�ڣ���ֹ�ɹ��˹�����������㳡��");
                        break;
                //
                case 5:
                        xywar_message("�ξ�̽�ӣ��ɹž����ѿ�ʼ���е�������ʱ�������ж���");
                        break;
                case 6:
                        xywar_message(dj_name + "�����Һ��ȫ���ڣ������ʼ���������ǡ�");
                        xywar_message(HIR "�ɹ�����30���ʼ���������ǣ���ע���غ����·�ڡ�" NOR);
                        xywar_message(HIY "ս������ʹ��ָ�� " HIR "xy" HIY " ��ʱ�鿴ս�����顣" NOR);
                        if (tiemuzhen)
                        {
                                xywar_message(HIG "ʤ��������1��ɱ���ɼ�˼��\t       " HIM "ʧ��������1���ɹ���ռ����������㳡\n" HIG
                                              "\t              2�������ɹ��˹���30����\t         " HIM "2�����вμ���������ս�����ʣ�಻������\n" HIG
                                              "\t              3��ȫ�������ɹ���\n" 
                                              HIG "\t              4���ɹ����˱�\n" NOR);
                        }
                        else
                        {
                                xywar_message(HIG "ʤ��������1�������ɹ��˹���30����\t       " HIM "ʧ��������1���ɹ���ռ����������㳡\n" HIG
                                              "\t              2��ȫ�������ɹ��ˡ�\t       " HIM "          2�����вμ���������ս�����ʣ�಻������\n" 
                                              HIG "\t              3���ɹ����˱�\n" NOR);                                
                        }

                        // 30����ɹž���ʼ����
                        remove_call_out("do_attack");
                        call_out("do_attack", 30);

                        call_out("do_attack_msg", 22, HIM "���ⷢ������ս��֮�����ɹž�ʿ����������");
                        call_out("do_attack_msg", 26, HIM "һ��Ϭ���غŽ���������ɽ�׶������������ɳ���ɹ��˾����ѿ�ʼ������");
                        
                        return;
                        break;

        }
        i += 1;
        remove_call_out("do_combatd_message");
        if (TEST)call_out("do_combatd_message", 2, i);
        else call_out("do_combatd_message", 50 + random(11), i);

        return;
}

// ֹͣ��������鱨���Ƿ�ﵽ����Ҫ��
void check_sign_up()
{
        string dj_name; // �󽫵�����        
        object ob;
        
        // ֹͣ����
        sign_up_status = 0;

        xywar_message(HIY "��������λ������ʿ���ܸ�л��ҵ�֧�֣�����ֹͣ�������������Ҿ�ͳ�Ƶı���������" NOR);
        xywar_message(HIW "���������������ܹ��� " HIY + chinese_number(sizeof(p)) + HIW " λ��ұ����μ���������ս��" NOR);

        // ���������ң��ӱ�����ɾ��֮
        sub_check_player();
                
        // �μ��������٣���������ս���ɹ����˱�
        if (sizeof(p) < 20 && ! TEST)
        {
                status = 0; // ����ս������־

                xywar_message("��λ������ʿ��������������ս������������20�ˣ���Ȼ������ˣ�Ҳ�գ�\n");

                if (tiemuzhen)dj_name = "�ɼ�˼��";
                else dj_name = "�󽫾�";

                switch(random(5))
                {
                         case 1:
                                 call_out("xywar_message", 4, "�ɹŸ���������" + dj_name + "���Ҿ�����ʿ��ͻȻȾ�����ߣ�Ŀǰ�Ѿ��޷�ս����");
                                 call_out("xywar_message", 6, dj_name + "���������д��£�����֪ͨȫ���������� ����");
                                 break;
                         case 2:
                                 call_out("xywar_message", 4, "�ɹ�̽�ӣ�����" + dj_name + "���������ھ�Ȼ���޶�����Ҳ�������صľ�ʿ������թ��");
                                 call_out("xywar_message", 6, dj_name + "�������е�����Ҳ���������ơ�����֪ͨȫ��Ѹ�ٳ�����Ȼ��ӳ����飡");
                                 break;
                         default:
                                 call_out("xywar_message", 4, "�ɹŰٷ򳤣�����" + dj_name + "���Ҿ��������޹���ȼ�������������ʧ������");
                                 call_out("xywar_message", 6, dj_name + "�ߣ����Ҵ��£��������ϳ�ȥ���ˣ�����֪ͨȫ�����ٳ��ˣ������ξ��˻�͵Ϯ��");
                                 break;
                }

                call_out("xywar_message", 8, "�α�����~~���ɹ���ͻȻ�������������Ϯ������ȫ�����أ�");

                call_out("xywar_over", 10);
                return;
        }
        
        // ���ѡ��һ��
        if (sizeof(p))player_leader = p[random(sizeof(p))];

        if (sizeof(player_leader))ob = find_player(player_leader);
        
        if (objectp(ob))
        {
                // ѡ����ҽ���
                xywar_message(HIG "������������ս��" + HIY + ob->name() + "(" + ob->query("id") + ")" HIG 
                                 "���������ؾ����죬���Ը���ս�����������ؾ�(xy xmove ����)��\n");
        }
        
        xywar_message("�α�����~~���ɹž�����������Ӻ�Χ�����������������׼��������(guard)�ɹž��ؾ�֮·��");

        // 10���Ӻ�ʼÿ��һ���Ӳ����ɹž������
        remove_call_out("do_combatd_message");
        call_out("do_combatd_message", 10, 1);

        return;
}

// �����������
int allot_soldier()
{
        int i, k;
        string *key_n_soldier;

        // ��������
        n_mg_tq = 40 + random(10);
        //n_mg_zb = 40 + random(10);
        n_mg_zb = 60 + random(20);
        //n_mg_gb = 60 + random(20);
        n_mg_gb = 120 + random(40);
        //n_mg_bb = 60 + random(20);
        n_mg_bb = 120 + random(40);
        n_xy_sb = 80 + random(20);

            // 1/5������ľ��
        if (random(5) == 1)tiemuzhen = 1;

        // ������ľ���������20%
        if (tiemuzhen)
        {
                n_mg_tq = n_mg_tq + n_mg_tq / 5;
                n_mg_zb = n_mg_zb + n_mg_zb / 5;
                n_mg_gb = n_mg_gb + n_mg_gb / 5;
                n_mg_bb = n_mg_bb + n_mg_bb / 5;
        }

        // ���ѡ��һ����ʿ���϶�
        key_n_soldier = keys(n_soldier);
        i = random(sizeof(key_n_soldier));        
        
        // �÷����϶�MORE_SOLDIER��ʿ��
        more_soldier_poision = key_n_soldier[i];
        
            // ({ ����ܱ𡢹����� ����  })
            // ƽ�����䵽����
        for (k = 0; k < sizeof(key_n_soldier); k ++ )
        {
                n_soldier[key_n_soldier[k]] = ({ n_mg_tq / 4,
                                                 n_mg_zb / 4,
                                                 n_mg_gb / 4,
                                                 n_mg_bb / 4,
                                               });
        }

            // ({ ����ܱ𡢹����� ����  })
            // ���һ����ʿ���϶�
        n_soldier[more_soldier_poision] = ({ n_mg_tq / 4 + MORE_SOLDIER,
                                             n_mg_zb / 4 + MORE_SOLDIER,
                                             n_mg_gb / 4 + MORE_SOLDIER,
                                             n_mg_bb / 4 + MORE_SOLDIER,
                                       });
                                      
        // ��¼����ɹž�����
        n_mg_sb2 = total_menggu_soldier("total");
        n_xy_sb2 = total_menggu_soldier("xiangyang");
        
        return 1;
}

// ��ʼ������
int init_soldier()
{
        /**
        1����ʼ������
        2����������ս�ȴ���־
        3�������ɹž���������ƶ������Ե�λ��
        4����������ʿ�������䵽�ĸ���
        **/        
        object ob, mg_dj;// �ɹŴ�
        string *key_doors;
        string re_route; // ������
        //int n_mg_tq, n_mg_zb, n_mg_bb, n_mg_gb, n_xy_sb;
        int i, n;

        // ���õȴ�������־
        status = WAIT_START;
        
        xy_guojing = new(XYNPC + "guo");
        if (tiemuzhen)mg_dj = new(XYNPC + "tiemuzhen");
        else mg_dj = new(XYNPC + "mgdajiang");

        // �������ȷ�����������и��ֱ��ַ���

        // 8��ǧ��
        for (i = 0; i < 8 ; i ++)
        {
                ob = new(XYNPC + "mgqianfuzhang");
                
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                
                // ���䵽�Ĵ���

                // ����
                if (i < 2)
                {
                        ob->set("route", "west");
                        ob->move(doors["east"]);
                }

                // ����
                if (i >= 2 && i < 4)
                {
                        ob->set("route", "north");
                        ob->move(doors["south"]);
                }

                // ����
                if (i >= 4 && i < 6)
                {
                        ob->set("route", "east");
                        ob->move(doors["west"]);
                }
                // ����
                if (i >= 6)
                {
                        ob->set("route", "south");
                        ob->move(doors["north"]);
                }
        }

        // 12���ٷ�
        for (i = 0; i < 12 ; i ++)
        {
                ob = new(XYNPC + "mgbaifuzhang");
                
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                // ���䵽�Ĵ���

                // ����
                if (i < 3)
                {
                        ob->set("route", "west");
                        ob->move(doors["east"]);
                }

                // ����
                if (i >= 3 && i < 6)
                {
                        ob->set("route", "north");
                        ob->move(doors["south"]);
                }

                // ����
                if (i >= 6 && i < 9)
                {
                        ob->set("route", "east");
                        ob->move(doors["west"]);
                }
                // ����
                if (i >= 9)
                {
                        ob->set("route", "south");
                        ob->move(doors["north"]);
                }
        }
        // 4������
        for (i = 0; i < 4; i ++)
        {
                ob = new(XYNPC + "mgfujiang");
                
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                // ���䵽�Ĵ���

                // ����
                if (i == 0)
                {
                        ob->set("route", "west");
                        ob->move(doors["east"]);
                }

                // ����
                if (i == 1)
                {
                        ob->set("route", "north");
                        ob->move(doors["south"]);
                }

                // ����
                if (i == 2)
                {
                        ob->set("route", "east");
                        ob->move(doors["west"]);
                }
                // ����
                if (i == 3)
                {
                        ob->set("route", "south");
                        ob->move(doors["north"]);
                }
        }

        n = n_mg_tq / 4;

        // n_mg_tq�������
        for (i = 0; i < n_mg_tq ; i ++)
        {
                ob = new(XYNPC + "mgqibing");
                
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                // ���䵽�Ĵ���

                // ����
                if (i < n)
                {
                        ob->set("route", "west");
                        ob->move(doors["east"]);
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        ob->set("route", "north");
                        ob->move(doors["south"]);
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        ob->set("route", "east");
                        ob->move(doors["west"]);
                }
                // ����
                if (i >= n * 3)
                {
                        ob->set("route", "south");
                        ob->move(doors["north"]);
                }
        }

        n = n_mg_zb / 4;

        // n_mg_zb���ܱ�
        for (i = 0; i < n_mg_zb ; i ++)
        {
                ob = new(XYNPC + "mgzhebie");
                
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                // ���䵽�Ĵ���

                // ����
                if (i < n)
                {
                        ob->set("route", "west");
                        ob->move(doors["east"]);
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        ob->set("route", "north");
                        ob->move(doors["south"]);
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        ob->set("route", "east");
                        ob->move(doors["west"]);
                }
                // ����
                if (i >= n * 3)
                {
                        ob->set("route", "south");
                        ob->move(doors["north"]);
                }
        }

        n = n_mg_gb / 4;

        // n_mg_gb������
        for (i = 0; i < n_mg_gb ; i ++)
        {
                ob = new(XYNPC + "mggongbing");
                
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                // ���䵽�Ĵ���

                // ����
                if (i < n)
                {
                        ob->set("route", "west");
                        ob->move(doors["east"]);
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        ob->set("route", "north");
                        ob->move(doors["south"]);
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        ob->set("route", "east");
                        ob->move(doors["west"]);
                }
                // ����
                if (i >= n * 3)
                {
                        ob->set("route", "south");
                        ob->move(doors["north"]);
                }
        }

        n = n_mg_bb / 4;

        // n_mg_bb������
        for (i = 0; i < n_mg_bb ; i ++)
        {
                ob = new(XYNPC + "mgbubing");
                
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                // ���䵽�Ĵ���

                // ����
                if (i < n)
                {
                        ob->set("route", "west");
                        ob->move(doors["east"]);
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        ob->set("route", "north");
                        ob->move(doors["south"]);
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        ob->set("route", "east");
                        ob->move(doors["west"]);
                }
                // ����
                if (i >= n * 3)
                {
                        ob->set("route", "south");
                        ob->move(doors["north"]);
                }
        }
        
        // ��more_soldier_poision�Ŷ�����MORE_SOLDIER��ʿ��        
        re_route = re_poision(more_soldier_poision);

        for (i = 0; i < MORE_SOLDIER ; i ++)
        {
                ob = new(XYNPC + "mgbubing");
                ob->set("route", re_route);
                ob->move(doors[more_soldier_poision]);                
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);

                ob = new(XYNPC + "mggongbing");
                ob->set("route", re_route);
                ob->move(doors[more_soldier_poision]);
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                ob = new(XYNPC + "mgqibing");
                ob->set("route", re_route);
                ob->move(doors[more_soldier_poision]);
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                
                ob = new(XYNPC + "mgzhebie");
                ob->set("route", re_route);
                ob->move(doors[more_soldier_poision]);
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);                
        }

        // ��¼����ʱ������û������ʿ��
        if (n_xy_sb <= 1)log_file("xiangyang_xysb", "ok at " + ctime(time()) + "\n");
        
        n = n_xy_sb / 4;

        // n_xy_sb������ʿ��
        for (i = 0; i < n_xy_sb ; i ++)
        {
                ob = new(XYNPC + "xyshibing");

                // ���䵽�Ĵ���
                // ����
                if (i < n)
                {
                        ob->set("route", "west");
                        ob->move(doors2["east"]);
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        ob->set("route", "north");
                        ob->move(doors2["south"]);
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        ob->set("route", "east");
                        ob->move(doors2["west"]);
                }
                // ����
                if (i >= n * 3)
                {
                        ob->set("route", "south");
                        ob->move(doors2["north"]);
                }
        }

        key_doors = keys(doors);

        // �����ƶ�������㳡
        xy_guojing->move("/d/xiangyang/guangchang");


        // �ƶ�NPC����Ӫǰ�����Ӫ����PLAYER
        clear_junying();
        
        // �ɹŴ��ƶ�����Ӫ
        if (tiemuzhen)
        {
                mg_dj = new(XYNPC + "tiemuzhen");
                mg_dj->move("/d/xiangyang/junying3");
                // ���ñ�����������ս�����к�
                mg_dj->set("ran_num", RAN_NUM);                
        }
        else
        {
                mg_dj = new(XYNPC + "mgdajiang");
                mg_dj->move("/d/xiangyang/junying3");
                // ���ñ�����������ս�����к�
                mg_dj->set("ran_num", RAN_NUM);                
        }

        // ����ǧ�򳤱�����
        for (i = 0; i < 2; i ++)
        {
                ob = new(XYNPC + "mgqianfuzhang");
                ob->move(environment(mg_dj));
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                if (tiemuzhen)                
                        ob->force_me("guard tie muzhen");                
                else
                        ob->force_me("guard menggu dajiang");
        }
        
        // �������ľ�������� 
        // 8��ǧ�򳤣�4��������20�����20���ܱ𱣻�
        if (tiemuzhen)
        {
                for (i = 0; i < 8; i ++ )
                {
                        ob = new(XYNPC + "mgqianfuzhang");
                        ob->move(environment(mg_dj));
                        ob->force_me("guard tie muzhen");
                        // ���ñ�����������ս�����к�
                        ob->set("ran_num", RAN_NUM);                        
                }
                                
                for (i = 0; i < 4; i ++ )
                {
                        ob = new(XYNPC + "mgfujiang");
                        ob->move(environment(mg_dj));
                        ob->force_me("guard tie muzhen");
                        // ���ñ�����������ս�����к�
                        ob->set("ran_num", RAN_NUM);                        
                }
                
                // Ҫ���ò�����ʿ��������־
                for (i = 0; i < 20; i ++ )
                {
                        ob = new(XYNPC + "mgqibing");
                        ob->set("no_total", 1);
                        ob->move(environment(mg_dj));
                        ob->force_me("guard tie muzhen");
                        // ���ñ�����������ս�����к�
                        ob->set("ran_num", RAN_NUM);                        
                }

                for (i = 0; i < 20; i ++ )
                {
                        ob = new(XYNPC + "mgzhebie");
                        ob->set("no_total", 1);
                        ob->move(environment(mg_dj));
                        ob->force_me("guard tie muzhen");
                        // ���ñ�����������ս�����к�
                        ob->set("ran_num", RAN_NUM);                        
                }
        }

        // �ƶ�10������10�����ֱ�����Ӫ��/d/xiangyang/junying1
        // �ػ�����north
        for (i = 0; i < 10; i ++)
        {
                ob = new(XYNPC + "mgbubing");
                ob->set("no_total", 1);
                ob->move("/d/xiangyang/junying1");
                ob->force_me("guard north");
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                ob = new(XYNPC + "mggongbing");
                ob->set("no_total", 1);
                ob->move("/d/xiangyang/junying1");
                ob->force_me("guard north");
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);                
        }

        // �ƶ�6��ǧ�򳤣�40���ܱ�40�������ػ���Ӫ/d/xiangyang/junying2
        for (i = 0; i < 6; i ++)
        {
                ob = new(XYNPC + "mgqianfuzhang");
                ob->move("/d/xiangyang/junying2");
                ob->force_me("guard north");
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);                
        }
        for (i = 0; i < 40; i ++)
        {
                ob = new(XYNPC + "mgzhebie");
                ob->set("no_total", 1);                
                ob->move("/d/xiangyang/junying2");
                ob->force_me("guard north");
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);
                                
                ob = new(XYNPC + "mgqibing");
                ob->set("no_total", 1);
                ob->move("/d/xiangyang/junying2");
                ob->force_me("guard north");
                // ���ñ�����������ս�����к�
                ob->set("ran_num", RAN_NUM);                
        }

        call_out("xywar_message", 2, "�ɹž����Ѿ��ִ��������ⰲӪ��կ������ȫ��������������");

        call_out("xywar_message", 15, "�α�̽�ӣ��˴��ɹž���������ԼΪ�� " HIY +
                                      sprintf("%d", total_menggu_soldier("total")) + HIC " �ˡ�");

        // ����֪ͨ��ҽ��б���
        call_out("xywar_message", 5, HIY "��������·�������ܣ�����ͬ�����ֽ��ɹ��˼���Χ�����������Σ����"
                                         "��Ը����������һ��������\n            �ٵ�" HIM "��������㳡" HIY "���б����ɣ�" NOR);

        // ���ÿɱ�����־
        sign_up_status = 1;

            // 5���Ӻ�ֹͣ����������鱨�������Ƿ�ﵽҪ��
        remove_call_out("check_sign_up");
        if (TEST)call_out("check_sign_up", 10);
        else call_out("check_sign_up", 300);

        return;
}
// ����Ԯ���ﵽ��Ķ���
void add_xy_soldier_action()
{
        call_out("xywar_message", 1, HIY "�ɹ�̽�ӣ���������Ԯ���Ѿ�������ϣ���ɢ���ĳ��ŵֿ��Ҿ���" NOR);
        
        if (random(2) == 1)        
                call_out("xywar_message", 3, HIY "�ɹŽ��죺�ߣ������������������Ĵ��������������ǿ�������������³ǳء�" NOR);
        else
                call_out("xywar_message", 3, HIY "�ɹŽ��죺����ȫ����ʿ��ǿ���ƣ����򲻿���У�������Ҫ˳������������" NOR);
}

// ��������ʿ��
void add_xy_soldier()
{
        object ob;
        string re_route; // ������
        int i, n, k;
        string *key_n_soldier;

        if (now_status() != WARRING && now_status() != WAIT_START && ! TEST)return;
        
        n_xy_sb = ADD_XY_SOLDIER;
        n = ADD_XY_SOLDIER / 4;
        
        // n_xy_sb������ʿ��
        for (i = 0; i < n_xy_sb ; i ++)
        {
                ob = new(XYNPC + "xyshibing");

                // ���䵽�Ĵ���
                // ����
                if (i < n)
                {
                        ob->set("route", "west");
                        ob->move(doors3["east"]);
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        ob->set("route", "north");
                        ob->move(doors3["south"]);
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        ob->set("route", "east");
                        ob->move(doors3["west"]);
                }
                // ����
                if (i >= n * 3)
                {
                        ob->set("route", "south");
                        ob->move(doors3["north"]);
                }
        }        


        // �޸�������������¼��
        n_xy_sb = n_xy_sb + ADD_XY_SOLDIER;

        xywar_message(HIY "����Ԯ���ѵִ������ǣ���ƽ����ɢ�����ŵ����ɹ��ˡ�");
        
        call_out("add_xy_soldier_action", 2); 
        
        return;
}

// �ⲿ���ã���������ʿ������ǰ�˵��ã������ӳ�Ч������
void add_xy_soldier_ext(object me)
{        
        // ����Ƿ�ɵ���
            if (now_status() != WARRING && now_status() != WAIT_START)
            {
                    write("ս����û�п�ʼ�ء�\n");
                    return;
            }            
        
        // ���ú����ӵ��ñ�־
        add_xyb_flag = 1;
        
        call_out("xywar_message", 2, HIR + me->name() + "ʹ�ñ��������������ؾ���" NOR);
        call_out("xywar_message", 4, HIR + "����Ԯ�����ڷ���͵�����Ԯ���ִ��ƽ����ɢ�����ŵֿ��ɹž���" NOR);
        call_out("xywar_message", 6, HIR + "����Ԯ�������ִ������ǣ�����ǰ�������ս��������" NOR);
        call_out("add_xy_soldier", 12);
}

// �ɹ����ɱ���Ԯ
// ��Ҫ�����÷�λ��ʱ���� yb_attack_where �����������Ϊ"none"����Ҫ��������
// Ŀ���ǽ�Ԯ��������ĳһ�����ϼ��У����ڹ���
void add_soldier()
{
        object ob;
        string re_route; // ������
        int i, n, k;
        string *key_n_soldier;

        // �������ȷ�����������и��ֱ��ַ���
        
        // 8��ǧ��
        for (i = 0; i < 8 ; i ++)
        {
                ob = new(XYNPC + "mgqianfuzhang");
                // ���䵽�Ĵ���

                // ����
                if (i < 2)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "west");
                                ob->move(doors["east"]);
                        }
                }

                // ����
                if (i >= 2 && i < 4)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "north");
                                ob->move(doors["south"]);
                        }
                }

                // ����
                if (i >= 4 && i < 6)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "east");
                                ob->move(doors["west"]);
                        }
                }
                // ����
                if (i >= 6)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "south");
                                ob->move(doors["north"]);
                        }
                }
        }

        // 12���ٷ�
        for (i = 0; i < 12 ; i ++)
        {
                ob = new(XYNPC + "mgbaifuzhang");
                // ���䵽�Ĵ���

                // ����
                if (i < 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "west");
                                ob->move(doors["east"]);
                        }
                }

                // ����
                if (i >= 3 && i < 6)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "north");
                                ob->move(doors["south"]);
                        }
                }

                // ����
                if (i >= 6 && i < 9)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "east");
                                ob->move(doors["west"]);
                        }
                }
                // ����
                if (i >= 9)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "south");
                                ob->move(doors["north"]);
                        }
                }
        }
        // 4������
        for (i = 0; i < 4; i ++)
        {
                ob = new(XYNPC + "mgfujiang");
                // ���䵽�Ĵ���

                // ����
                if (i == 0)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "west");
                                ob->move(doors["east"]);
                        }
                }

                // ����
                if (i == 1)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "north");
                                ob->move(doors["south"]);
                        }
                }

                // ����
                if (i == 2)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "east");
                                ob->move(doors["west"]);
                        }
                }
                // ����
                if (i == 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "south");
                                ob->move(doors["north"]);
                        }
                }
        }

        n = n_mg_tq / 4;

        // n_mg_tq�������
        for (i = 0; i < n_mg_tq ; i ++)
        {
                ob = new(XYNPC + "mgqibing");

                // ���䵽�Ĵ���

                // ����
                if (i < n)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "west");
                                ob->move(doors["east"]);
                        }
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "north");
                                ob->move(doors["south"]);
                        }
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "east");
                                ob->move(doors["west"]);
                        }
                }
                // ����
                if (i >= n * 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "south");
                                ob->move(doors["north"]);
                        }
                }
        }

        n = n_mg_zb / 4;

        // n_mg_zb���ܱ�
        for (i = 0; i < n_mg_zb ; i ++)
        {
                ob = new(XYNPC + "mgzhebie");

                // ���䵽�Ĵ���

                // ����
                if (i < n)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "west");
                                ob->move(doors["east"]);
                        }
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "north");
                                ob->move(doors["south"]);
                        }
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "east");
                                ob->move(doors["west"]);
                        }
                }
                // ����
                if (i >= n * 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "south");
                                ob->move(doors["north"]);
                        }
                }
        }

        n = n_mg_gb / 4;

        // n_mg_gb������
        for (i = 0; i < n_mg_gb ; i ++)
        {
                ob = new(XYNPC + "mggongbing");

                // ���䵽�Ĵ���

                // ����
                if (i < n)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "west");
                                ob->move(doors["east"]);
                        }
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "north");
                                ob->move(doors["south"]);
                        }
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "east");
                                ob->move(doors["west"]);
                        }
                }
                // ����
                if (i >= n * 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "south");
                                ob->move(doors["north"]);
                        }
                }
        }

        n = n_mg_bb / 4;

        // n_mg_bb������
        for (i = 0; i < n_mg_bb ; i ++)
        {
                ob = new(XYNPC + "mgbubing");

                // ���䵽�Ĵ���

                // ����
                if (i < n)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "west");
                                ob->move(doors["east"]);
                        }
                }

                // ����
                if (i >= n && i < n * 2)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "north");
                                ob->move(doors["south"]);
                        }
                }

                // ����
                if (i >= n * 2 && i < n * 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "east");
                                ob->move(doors["west"]);
                        }
                }
                // ����
                if (i >= n * 3)
                {
                        if (yb_attack_where != "none")
                        {
                                ob->set("route", re_poision(yb_attack_where));
                                ob->move(doors[yb_attack_where]);
                        }
                        else
                        {                
                                ob->set("route", "south");
                                ob->move(doors["north"]);
                        };
                }
        }
        
        // ��more_soldier_poision�Ŷ�����MORE_SOLDIER��ʿ��        
        re_route = re_poision(more_soldier_poision);

        for (i = 0; i < MORE_SOLDIER ; i ++)
        {
                ob = new(XYNPC + "mgbubing");
                ob->set("route", re_route);
                ob->move(doors[more_soldier_poision]);

                ob = new(XYNPC + "mggongbing");
                ob->set("route", re_route);
                ob->move(doors[more_soldier_poision]);
                
                ob = new(XYNPC + "mgqibing");
                ob->set("route", re_route);
                ob->move(doors[more_soldier_poision]);

                ob = new(XYNPC + "mgzhebie");
                ob->set("route", re_route);
                ob->move(doors[more_soldier_poision]);
        }

        // �޸��ɹž�������¼��
        key_n_soldier = keys(n_soldier);

        for (k = 0; k < sizeof(key_n_soldier); k ++ )
        {
                n_soldier[key_n_soldier[k]] = ({ n_soldier[key_n_soldier[k]][0] + n_mg_tq / 4,
                                                 n_soldier[key_n_soldier[k]][1] + n_mg_zb / 4,
                                                 n_soldier[key_n_soldier[k]][2] + n_mg_gb / 4,
                                                 n_soldier[key_n_soldier[k]][3] + n_mg_bb / 4,
                                               });
        }

            // ({ ����ܱ𡢹����� ����  })
            // ���һ����ʿ���϶�
        n_soldier[more_soldier_poision] = ({ 
                                             n_soldier[more_soldier_poision][0] + MORE_SOLDIER,
                                             n_soldier[more_soldier_poision][1] + MORE_SOLDIER,
                                             n_soldier[more_soldier_poision][2] + MORE_SOLDIER,
                                             n_soldier[more_soldier_poision][3] + MORE_SOLDIER,
                                          });

        xywar_message(HIR "�ɹ�����Ԯ�����ѵִ���������׼����ʼ���ǡ�");

        // ɢ�������Ϣ
        if (yb_attack_where != "none")
        {
                string string_ran_doors = random_doors_name();
                
                xywar_message(HIY "�ɹŴ󽫣��ɹ�Ԯ��������зֶӳ���" + HIR + string_ran_doors +
                              HIY "�����������������" NOR);
                xywar_message(NOR + YEL "��̼䣬��" + string_ran_doors + NOR + YEL "��Զ�����������"
                              "�ƺ��ۼ��˴������ӡ�" NOR);
        }

        return;
}

// ������ʿ֧Ԯ
void support_npc()
{
        object ob1, ob2, ob3, ob4;
        string guard_door,guard_door_name;
        string *sp;
        string pos;
        
        if (random(10) > 3 && ! TEST)return;
        
        switch(random(2))
        {
                // �����С��Ů
                case 0:
                        call_out("xywar_message", 2, HIW "��������������ֽ��������ѣ���ɱ�ɹ��������ܲ������һ�ݣ�" NOR);
                        call_out("xywar_message", 5, HIW "С��Ů���������㵽�Ķ��Ҿ͸��㵽�Ķ� ����" NOR);
                        call_out("xywar_message", 8, HIY "������Ц���úúã��ж��Ա�������Ϊ���Σ��й�������������ڣ��Ҿͷ����ˣ�" NOR);
                        // ���ѡ��һ�����ػ�
                        sp = keys(doors2);
                        pos = sp[random(sizeof(sp))];
                        guard_door = doors2[pos];
                        guard_door_name = doors2_name[pos];
                        call_out("xywar_message", 12, HIW "������Һ�����Ҳ��·���˵أ���˵�ɹ��˽�ҪΧ�������ǣ����Ա���������" NOR);
                        call_out("xywar_message", 15, HIW "������Һ�����������Ҫ��������һ��֮�������������ǡ�" NOR);
                        call_out("xywar_message", 18, HIW "С��Ů���˹���һ�۵��˵�ͷ��" NOR);
                        call_out("xywar_message", 20, HIY "����������˵�����ã������������Ǿ��ػ�" + HIR + guard_door_name + HIY "�ɣ�" NOR);
                        call_out("xywar_message", 22, HIW "�Աϣ������С��Ůֱ��" + guard_door_name + "��" NOR);
                        
                        ob1 = new(YANGGUO);
                        ob2 = new(LONGNV);

                        ob1->move(guard_door);
                        ob1->force_me("guard " + re_poision(pos));
                        ob2->move(guard_door);
                        ob2->force_me("guard " + ob1->query("id")); // С��Ůֻ�������
                        ob1->set("mate", ob2);
                        ob2->set("mate", ob1);
                        
                        xy_msg1 = "�����С��Ůǰ��֧Ԯ���ػ�" + HIR + guard_door_name;
                        break;

                // ��а��
                case 1:
                        call_out("xywar_message", 2, HIW "��ҩʦ���ߣ��ɹ����Ӿ�Ȼ������ţ��һ���а��ƫҪ�����ǻ�ᣡ" NOR);
                        call_out("xywar_message", 6, HIY "ŷ���棺����������Ȼ����а��������ˣ���������ŷ�������ܲ��մ����֣���������" NOR);
                        call_out("xywar_message", 10, HIM "һ�ƴ�ʦ˫�ֺ�ʮ�������������²����ֽ�����𺣣�����Ϳ̿�������������Ӳ���" NOR);
                        call_out("xywar_message", 14, HIG "���߹�����������ô���֣����Ͻл��ӿɲ��ܴ������" NOR);
                        call_out("xywar_message", 18, HIC "����һ���˷ܣ��úúã������о��ˣ�" NOR);
                        call_out("xywar_message", 20, HIR "��˵��а���������ϵۡ���ؤ�Ĵ���ʦ���뵽��������ս���У���ͬ�����ɹ��ˡ�" NOR);
                        
                        ob1 = new(DONGXIE);
                        ob2 = new(XIDU);
                        ob3 = new(NANDI);
                        ob4 = new(BEIGAI);
                        ob1->move(doors2["east"]);
                        ob1->force_me("guard " + "west");
                        ob2->move(doors2["west"]);
                        ob2->force_me("guard " + "east");
                        ob3->move(doors2["south"]);
                        ob3->force_me("guard " + "north");
                        ob4->move(doors2["north"]);
                        ob4->force_me("guard " + "south");        

                        xy_msg1 = "��а���������ϵۡ���ؤ�Ĵ����ǰ����Ԯ���ֱ��ػ����š�";        

                        break;
                        
                default:
                        return;
        }
}

void start_story(int i)
{
        string *story = ({
                "�γ�ĩ�꣬��͢��ӹ���ܣ��ɹ��˴�ٷ��Σ���������Ϳ̿�������� ����",
                "���������γ�ս��Ҫ�أ�������Ϊ��ȡ�������ɹ��������ر�Χ�� ����",
                "���ǣ��������ط򸾳���������������ʿ�����سǳأ���ǿ�ֿ������ɹ��˾ù����¡�",
                "�ɹž�Ӫ ����",
                "�ɼ�˼����������ȡ�����Գɾ����ɹŴ�ҵ��������Ҫ���ɱ���ǿ�������ǣ�",
                "�ɼ�˼�������Һ�����ɱ�����׼��ǿ���������˴�һ��Ҫ�����������¡�",
                HIR "��ʾ���ɹųɼ�˼���ɳ��ر�����������" NOR,
                "�������ڡ�"
                "�α�����������ǰ��̽�ӻر����ɹ������ɱ�ֱ������������",
                "�����������ɹ��˾ù��������£����һ���ּ��ر�������ǿȡ�������ǡ�",
                "�������˶ٶ��α��Ը����������������о�ʿ��ǿ�䱸���ȴ����",
                "�α�Ӧ��һ��ת���ȥ��",
                "������̾��������ɹ��˴�ٽ�����������֪����Ҫ�ж����޹�������������...",
                "�������˶ٶ�����һ�ԵĻ���˵��������ɹ����������ڣ�������־�ڱصã���Ŀǰ�����ǵı������¼��ز��˶�ã�\n"
                "            ��֪�ض�����ʲô�ð취���԰����ɹ���һ��Σ�ѣ���ס�����ǣ�",
                "����վ���ڷ�������һȦ�Թ���˵������Ŀǰ�����ƿ�����ǿ����������⿿������Ŀǰ���������� ����",
                "���ض��˶��ֵ��������Ծ������Ĵ�������ļ����Ӣ�ۺ������˹�ͬ��ս����ɱ�ס�����ǡ�",
                "������Ȼ����һ�����ӽ�����˼���Ļ�������һ�������ã�����ô�����ˣ����������ζ�Ҫ��ס�����ǡ�",
                "���أ�@@",
                "��ʱ��һλ�α����Ҵҵ����˽�����������������̽�ӻر����ɹž��ѱƽ���������Լ����Ӻ�ɵִ���⣡",
                "������ɫ������������ȫ���ʿ������������ʱ׼�����ɹ��˿�ս��",
                "�ξ�Ӧ��һ����ת���ܳ�ȥ��",
                "�����ͻ��ص�����̸�˼����Ҳ���ų�ȥ��ֱ����Ӫ ���� ��սһ��������",
                HIR "��ʾ���ɹž��ӽ�������Ӻ�ִ��������⣬��������������ֹͣ���������޹��ܺ�������" NOR,
        });
        
        
        
        // ����Ӻ�
        // �����Ӻ�
        // ����ж��Ƿ񽭺���ʿ����
        if (i >= sizeof(story))
        {
                remove_call_out("init_soldier");
                if (TEST)call_out("init_soldier", 5);
                else call_out("init_soldier", 300); // ��ʼ����Ҫ����
                
                // ������ʿ��Ԯ����
                remove_call_out("support_npc");
                if (TEST)call_out("support_npc", 2);
                else call_out("support_npc", 120);
                
                return;
        }

        xywar_message(story[i]);
        i += 1;

        remove_call_out("start_story");
        call_out("start_story", 4, i);
        return;
}

// ��ʼ����ս
void start_xywar()
{
        /*
        1��������������������ſ�ʼ�����������
        2��1���������Ӻ��ʼ��-->init_soldier()
        3����ʽ����ս��
        */

        start_status = 1;    // ������ڿ�ʼ����ϵͳ�ظ�����
        start_time = time();  // ���ÿ�ʼʱ��

        RAN_NUM = 100 + random(900); // ����������������ս���кţ�����λ��
        
        allot_soldier(); // �����������

        // ��ʼ��������
        start_story(0);

}

// ���ر�����ҽ���
// ������˳�ս���򷵻� ���ޡ�
string leader_player()
{        
        if (! if_sign_up(player_leader))return "��";
        
        return player_leader;
}

// ��ҿɿ��������ؾ�
// 1����ѯĿǰ�ؾ������ص�
// 2�������ؾ����ϱ��������ص�
// �������ʿ���������޷�����ʾ
// �ɹž���ǲԮ����1�������޷���ѯ

// ��ѯ�ؾ����ɹž����
void show_soldier(object me)
{
        int total, xytotal, w, e, s, n;
        string msg;
        
        total = total_menggu_soldier("total");
        xytotal = total_menggu_soldier("xiangyang");
        w = total_menggu_soldier("west");
        e = total_menggu_soldier("east");
        s = total_menggu_soldier("south");
        n = total_menggu_soldier("north");
                
        msg =  HIR "\n����̽�ӵ���Ϣ��������������ս����\n" NOR;
        msg += HIC "--------------------------------------------------------------------\n" NOR;
        if (time() - last_move_xysolder < 60)
        {
                msg += HIG "�ɹž��������˴���Ԯ����Ŀǰ׼ȷ�������ڴ�̽���� ����\n" NOR;
        }
        else
        {
                msg += HIG "�ɹž�������" HIR + sprintf("%d", total) + HIG "�ˣ����У�" 
                       "������" HIR + sprintf("%d", e) + HIG "�ˣ���ȸ��" HIR + sprintf("%d", s) + HIG "�ˣ�"
                       "�׻���" HIR + sprintf("%d", w) + HIG "�ˣ�������" HIR + sprintf("%d", n) + HIG "�ˡ�\n" NOR;
        }

        msg += HIW "�����ؾ�������: " HIR + sprintf("%d", xytotal) + HIW "�ˣ���Ҫ������" HIR + 
               xy_soldier_poision("name") + "(" + xy_soldier_poision("poision") + HIW ")��\n" NOR;    
        msg += HIC "--------------------------------------------------------------------\n" NOR;        

        tell_object(me, msg);
        
        return;
}


// ���������ؾ�
// Ȩ����/cmds/usr/xy.c �����ж�
void move_xysoldier(object me, string p)
{
        int xytotal;
        string msg, dj_name;
        
        if (now_status() != WARRING && now_status() != WAIT_START)
        {
                write("��������ս��û�п�ʼ�����޷����������ؾ���\n");
                return;
        }
        
        // �ϴε���ʱ��������ΪMOVE_WAIT��
        if (time() - last_move_xysolder < MOVE_WAIT)
        {
                write("�����ϴε��������ؾ�ʱ�䲻��60�룬ʿ��ƣ�����޷�����������\n");
                return;
        }
        
        xytotal = total_menggu_soldier("xiangyang");
        
        if (xytotal < 5)
        {
                write("Ŀǰ�����ؾ�����̫�٣��޷����е�����\n");
                return;
        }
        
        if (p != "west" && p != "east" && p != "north" && p != "south")
        {
                write("��Ҫ�������ؾ����ĸ����������(west|north|east|south)\n");
                return;
        }
        
        // ���������ؾ��µķ��ط���
        xysb_poision = p;
        
        // ���õ���ʱ��
        last_move_xysolder = time();
        
        write("���Ѿ�������������ؾ��������ؾ�������" + HIY + xy_soldier_poision("name") + NOR "�ص�����ɹ��ˡ�\n" NOR);
        
        xywar_message(HIG + me->name() + "���ڵ��������ؾ��������ؾ��Ѿ�����" + HIY + xy_soldier_poision("name") + HIG "�ص�����ɹ��ˡ�\n" NOR);
        
        if (tiemuzhen)dj_name = "�ɼ�˼��";
        else dj_name = "�ɹŴ�";
        
        switch(random(5))
        {
                case 0:
                        msg = "�ߣ��˴����������ڱصã���ֻ���ξ����������ĵֿ���";
                        break;
                case 1:
                        msg = "�����������С�������������ѻ�ʯ���۵������ѡ�";
                        break;                        
                case 2:
                        msg = "�ף��δ��ξ������Ǻ�����Ҳ����Ȼ��������ñ���������ԭ�˲ű������ҵ��в�����С�";
                        break;
                
                default:
                        msg = "�ߣ����ɹ���ʿ��һ��ʮ�����������б����������ɹ��˵����档";
                        break;                
        }
        
        msg = HIM + dj_name + "��" + msg + NOR;

        xywar_message(msg);
        
        return;
}


// �����ɹž�ս��
// ����Ԯ��
void combat_add_soldier()
{
            
            // �������ADD_MGB_TIMES��
            if (add_mgb_times >= ADD_MGB_TIMES)
            {
                    write("��Ԯ�����ѴＫ�ޡ�\n");
                    return;
            }

            if (now_status() != WARRING && now_status() != WAIT_START)
            {
                    write("ս����û�п�ʼ�ء�\n");
                    return;
            }

            last_add_mgb_time = time();
            add_mgb_times += 1;
            
            write(HIW "�������ɳ��ɹž���Ԯ��\n" NOR);

            // ��ʼ׼������            
            xywar_message(HIR "�ɹ��˵�ȼ�����̣�֪ͨ�ɹž���Ԯ��" NOR);

            // �ӳ��ɱ�
            remove_call_out("delay_add_soldier");
            call_out("delay_add_soldier", 30 + random(10));

            call_out("xywar_message", 3, HIR "�ɹ�Ԯ���Ѿ��յ�ѶϢ��׼����ʼ������");
            call_out("xywar_message", 8, HIR "�ɹ���Ԯ�����ѿ�ʼ��̣��ܿ콫�ﵽ������");
            call_out("xywar_message", 15, HIR "�ɹ�Ԯ������ҹ��·�������ִ������ǡ�");
}

// �ɹ��ӳ��ɱ�
void delay_add_soldier()
{
        if (now_status() != WARRING && ! TEST)return;

        // �ɱ���Ԯ
        add_soldier();
}

// ս��������˱�
void combat_xjtuibing()
{
        
}

// ս������������
void combat_sdjixi()
{
        
}

// ���б�������ĳ��
// ����pos Ϊ����ָ����������㳡�ķ��� west,east,north,south
void combat_attack_all(string pos)
{
        // 50%�������˵����������
        if (random(2) == 1)
        {
        }
        
        
        
}