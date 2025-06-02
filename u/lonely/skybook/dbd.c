// ultra_questd.c
// Create by Rcwiz for Heros.cn 2004/06/02
// ����

#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;

void set_from_dbase_add_temp(string uid, mixed data, mixed preobj0, mixed preobj1, mixed preobj2)
{
        string s0, s1, s2, sdata;
        
        s0 = "";
        s1 = "";
        s2 = "";
        
        if (objectp(preobj0))s0 = base_name(preobj0);
        if (objectp(preobj1))s1 = base_name(preobj1);
        if (objectp(preobj2))s2 = base_name(preobj2);
        
        if (intp(data))sdata = sprintf("%d", data);
        
        log_file("0add_temp", "id = " + uid + ", p0 = " + s0 + ", p1 = " + s1 + ", p2 = " + s2 + ", sdata=" + sdata + "\n");
        
        
}

void create()
{
        seteuid(getuid());
        restore();
}

public string query_save_file() { return DATA_DIR "dbd"; }

// �������ú���
// ����һ��mapping ��ֵΪ��ֵ��
// Ϊ��mapping ������ֵ���дӸߵ��͵����򣬷��ظ�mapping ��������
public string *tongji_mapping(mapping mp, int flag)
{
        string key_mp;
        string *result_mp, *temp_s1, *temp_s2, *temp_s3;
        string *str_temp;
        int i;
        
        temp_s1 = ({});
        temp_s2 = ({});
        temp_s3 = ({});
                
        if (! sizeof(mp))return temp_s1;

        // �Ƚ�mp�е�������ֵ���� ֵ:���� ��ʽ��ϣ�Ȼ��� ֵ:���� �ɴ�С����
        result_mp = keys(mp);

        for (i = 0; i < sizeof(result_mp); i ++)
        {
                temp_s1 += ({ sprintf("%06d", mp[result_mp[i]]) + ":" + result_mp[i] });
        }
        temp_s2 = sort_array(temp_s1, -1);
        
        for (i = 0; i < sizeof(temp_s2); i ++)
        {
                str_temp = ({});
                str_temp = explode(temp_s2[i], ":");
                temp_s3 += ({ str_temp[1] });
        }

        return temp_s3;
}

// �õ������½QQ�б�
string *get_permit_list()
{
        restore();
        return query("permit_list");
}

// �õ��ܾ���½QQ�б�
string *get_deny_list()
{
        restore();
        return query("deny_list");
}

void record_list(string qq, string s_type)
{
        string *deny_list, *permit_list;

        deny_list = get_deny_list();
        permit_list = get_permit_list();

        if (! deny_list)deny_list = ({});
        if (! permit_list)permit_list = ({});

        if (s_type == "deny") 
        {
                deny_list += ({ qq });
                set("deny_list", deny_list);
                save();
        }
        if (s_type == "permit")
        {
                permit_list += ({ qq });
                set("permit_list", permit_list);
                save();
        }
        write("OK\n");
        return;
}

// �õ����������Ϣ
string query_crave()
{
        string msg;
        int i;
        mapping t;
        string *temp;

        restore();

        t = query("haigui");
        if (! t)return "";

        temp = keys(t);

        msg = "";
        for (i = 0; i < sizeof(temp); i ++)
        {
                msg = msg + t[temp[i]]["name"]+"(" + temp[i] + ")��" + t[temp[i]]["msg"] + "\n";
        }
        
        return msg;             
}

int do_crave(object me, string arg)
{
        if (! arg)
        {
                tell_object(me, "��Ҫ��ʲô��\n");
                return 1;
        }

        if (! me->query("luck_number"))
        {
                tell_object(me, "�㻹û��ע���أ�����ָ�� help reg �鿴ע����Ϣ��\n");
                return 1;
        }       
        if (sizeof(arg) > 60)
        {
                tell_object(me, "��Ҫ��̵���Ϣ���������ܳ�����ʮ�����ֻ���ʮ���ַ���\n");
                return 1;
        }

        set("haigui/" + me->query("id") + "/msg", arg);
        set("haigui/" + me->query("id") + "/name", filter_color(me->name()));
        save();

        tell_object(me, HIG "��ɹ������꺣�걳�ϵ������Ϣ��\n" NOR);
        return 1;
}

int set_data(string darg, mixed ddata)
{
        set(darg, ddata);

        save();
}

mixed query_data(string arg)
{
        restore();
        if (query(arg))return query(arg);

        return 0;               
}

int delete_data(object me, string str)
{
        //if (! wizardp(me))return 0;

        delete(str);
        save();

        return 1;
}

// ͳ����ͳ����SCB����
// flag = 1 ͳ��������flag = 2ͳ���ж�����һ���SCB
public int get_scb_total(int flag)
{
        mapping scb;
        string *key_scb;
        int i, n, total_scb;
        
        scb = query("yhshop/scb");
        
        if (sizeof(scb))key_scb = keys(scb);
        
        if (! sizeof(key_scb))return 0;
        
        n = 0;
        total_scb = 0;
        
        for (i = 0; i < sizeof(key_scb); i ++)
        {
                if (scb[key_scb[i]] < 1)continue;
                // ��ʦ��ͳ��
                if (key_scb[i] == "rcwiz" || key_scb[i] == "cdlove")continue;
                
                n ++;
                total_scb += scb[key_scb[i]];
        }
        
        if (flag == 1)return total_scb;
        if (flag == 2)return n;
        
        return 0;
}
