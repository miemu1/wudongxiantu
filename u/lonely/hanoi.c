// hanoi.c
// ��ŵ����һ�ֹ��ϵ���ѧ��Ϸ������������(base)��һ��ʼ
// ���е����Ӷ�����С�����˳����ϵ��µķ��ڵ�һ������
// (base/A)���Ҫ���ǰѵ�һ�������е��������õڶ�����
// ��(base/B)ȫ���Ƶ������������С�����С������ֻ�ܷ���
// ����������棬ÿ��ֻ���ƶ�һ�����ӡ������Ŀ�����õ�
// ��ķ������(���ٵ���ɲ��� = 2 ^ ������Ŀ - 1)��

#include <ansi.h>
#define MAX my["max"] // �ܹ�������
#define START my["start"] // ��ʼ��Ϸ��
#define BASE my["base"] // ������״̬
#define STEP my["step"] // ���ߵĲ���

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;

int do_help(string arg);

int query_autoload() { return 1; }
string query_save_file() { return __DIR__ "hanoi/" + query("start"); }

void create()
{
        set_name(HIY "��ŵ��" NOR, ({ "hanoi" }));
        set_weight(100);

        set("long", "����һ�׹�����ѧ��Ϸ��ŵ����ģ�͡�\n");
        set("unit", "��");

        set("base", ([
                "A" : ({ }),
                "B" : ({ }),
                "C" : ({ }),
        ]));
}

// �ṩָ��
void init()
{
        add_action("do_new", "new");       // �� �� Ϸ
        add_action("do_stop", "stop");     // ������Ϸ
        add_action("do_record", "record"); // ������Ϸ
        add_action("do_load", "load");     // ������Ϸ
        add_action("do_move", "move");     // �ƶ�����
        add_action("do_help", "help");     // ������Ϣ
}

// ��ʾĿǰ״̬
string long()
{
        mapping my = query_entire_dbase();
        mapping info;
        string *msg, line, base, long;
        int i, j, max;

        if( !START )
                return my["long"];

        info = ([ ]);
        max = MAX * 2 + 4;
        foreach( base in keys(BASE) ) {
                msg = ({ });
                BASE[base] = sort_array(BASE[base], 1);
                for( i = 0; i < MAX; i++ ) {
                        j = i - (MAX - sizeof(BASE[base]));

                        if( j < 0 )
                                line = repeat_string(" ", (max - 2) / 2) + WHT "��" NOR +
                                repeat_string(" ", (max - 2) / 2);
                        else {
                                line =  repeat_string(" ", (max - BASE[base][j] * 2) / 2) +
                                        CYN + repeat_string("��", BASE[base][j]) + NOR +
                                        repeat_string(" ", (max - BASE[base][j]* 2) / 2);
                        }

                        msg += ({ line });
                }
                info[base] = msg;
        }
        set("info", info);
        long = WHT "����" + ((! STEP) ? "��һ����û��" 
                : "�Ѿ����� " + STEP + " ��") + "��\n\n" + NOR;

        for (i = 0; i < MAX; i++)
        {
                long += sprintf("%s%s%s\n", info["A"][i], info["B"][i], info["C"][i]);
        }
        return long;
}

int do_new(string arg)
{
        object me = this_player();
        mapping my = query_entire_dbase();
        int i, max;

        if (stringp(START))
                return notify_fail("��Ϸ�Ѿ���ʼ�ˣ������ֹͣ����\n");

        if (! arg) max = 3;
        else if (! sscanf(arg, "%d", max) || max > 9)
                return notify_fail("����ĸ�ʽ����\n");

        START=query("id", me);
        MAX = max;
        STEP = 0;
        for (i = 0; i < max; i++)
        {
                BASE["A"] += ({ i + 1, });
        }

        write("��Ϸ������ϣ�����(help here)���Ի�ð�����\n");
        write(long());
        return 1;
}

void end_game()
{
        delete("max");
        delete("start");
        delete("base");
        delete("step");
        set("base", ([
                "A" : ({ }),
                "B" : ({ }),
                "C" : ({ }),
        ]));
}

int do_move(string arg)
{
        object me = this_player();
        mapping my;
        string from, to;

        if (! arg || sscanf(arg, "%s to %s", from, to) != 2)
                return do_help("move");

        if (from == to)
                return notify_fail("���Գ��ˣ�\n");

        my = query_entire_dbase();

        if( query("id", me) != START )
                return notify_fail("��ɱ��Ҷ���\n");

        if (member_array(from, keys(BASE)) == -1 ||
            member_array(to, keys(BASE)) == -1)
                return notify_fail("����ֻ������" + implode(keys(BASE), "��") + "����֮һ��\n");

        if (! sizeof(BASE[from]))
                return notify_fail("����" + from + "�����û������ѽ��\n");

        BASE[from] = sort_array(BASE[from], 1);
        BASE[to] = sort_array(BASE[to], 1);

        if (sizeof(BASE[to]) && sizeof(BASE[from]) && BASE[to][0] < BASE[from][0])
                return notify_fail("������Ӳ��ܷ���С���������档\n");

        tell_object(me, WHT "��ѵ���" + from + "��" + chinese_number(BASE[from][0])+ "�������ƶ����˵���" + to + "�ϡ�\n" NOR);

        BASE[to] = ({ BASE[from][0] }) + BASE[to];
        BASE[from] -= ({ BASE[from][0] });
        STEP++;
        write(long());

        if (sizeof(BASE["C"]) == MAX)
        {
                write(WHT "\n��ϲ���������Ϸ��\n" NOR);
                end_game();
        }

        return 1;
}

int do_stop(string arg)
{
        object me = this_player();
        mapping my;

        my = query_entire_dbase();

        if (! stringp(START))
                return notify_fail("��û��ʼ�أ�������ɶ��\n");

        if( query("id", me) != START )
                return notify_fail("ֻ����Ϸ�����߲��ܽ��������Ϸ��\n");

        end_game();
        write(WHT "������˵�ǰ����Ϸ��\n" NOR);
        return 1;
}

int do_record(string arg)
{
        object me = this_player();
        mapping my;

        my = query_entire_dbase();

        if (! stringp(START))
                return notify_fail("��û��ʼ�أ������ɶ��\n");

        if( query("id", me) != START )
                return notify_fail("ֻ����Ϸ�����߲��ܱ�����Ϸ��\n");

        save();
        write(WHT "��ǰ��Ϸ������ϡ�\n" NOR);
        return 1;
}

int do_load(string arg)
{
        object me = this_player();
        mapping my;

        my = query_entire_dbase();

        if (stringp(START))
                return notify_fail("��Ϸ�Ѿ���ʼ�ˣ��㻹���Ȱ���ֹͣ�ɡ�\n");

        if( file_size(__DIR__"hanoi/"+query("id", me)+".o") <= 0 )
                return notify_fail("�㲢û�б������Ϸѽ��\n");

        START=query("id", me);
        restore();
        write(WHT "��һ�ε���Ϸ������ϡ�\n" NOR);
        write(long());
        return 1;
}

int do_help(string arg)
{
switch (arg)
{
case "here":
        write(@HELP
�����������ʹ��������Щ�ͺ�ŵ����ص����
new ��ʼһ������Ϸ
stop ���������Ϸ
record ���浱ǰ����Ϸ
load ���뱣�����Ϸ
move �ƶ�һ������
HELP );
        break;

case "new":
        write(@HELP_NEW
ָ���ʽ : new [������Ŀ]

��ָ�����㿪ʼһ���µĺ�ŵ����Ϸ�������׺�ŵ���Ѿ���ʼ����Ϸ
ʱ��������Ȱ������Ϸ�ر�(stop)����Ϊ���ڹر�ǰ����(record)��
�����ָ����Ϸ�г�ʼ���ӵ���Ŀ������಻�ó��� 9����һ��ʼ��
�ӻ�ȫ�����ŵ����� A�У�����Ҫ������ȫ��һ������(move)������
C �о���Ӯ��ʤ����ע�⣺������Ӳ��÷���С���������档

���ָ�stop, record, move
HELP_NEW );
        break;

case "stop":
        write(@HELP_STOP
ָ���ʽ : stop

ֹͣ�����Ϸ��������������Ϸ�Ľ����߲�����ô����

HELP_STOP );
        break;

case "record":
        write(@HELP_RECORD
ָ���ʽ : record

��ָ�����㱣���������ڽ��е���Ϸ�Ա��´μ����棬����������
��Ϸ�Ľ����߲�����ô���������Ժ������(load)��û����Ϸ���ڽ�
�е�����µ��롣ע�⣺��������� ID ��ǰ�Ѿ��������Ϸ����ô
�����ǰ����Ϸ�������ǵ���

���ָ�load
HELP_RECORD );
        break;

case "load":
        write(@HELP_LOAD
ָ���ʽ : load

����һ�����ϴ������Ϸ������ֹͣ(stop)Ŀǰ����Ϸ��˵��

���ָ�record, stop
HELP_LOAD);
        break;

case "move":
        write(@HELP_MOVE
ָ���ʽ : move A to B

�ѵ��� A��B��C ���������һ�������ƶ�����һ��������ȥ�����
���Ӳ��÷���С���������档����ѵ��� A ���������Ӷ��Ƶ��˵�
�� C �У��ͻ��ʤ�����������Ϸ��
HELP_MOVE );
        break;

default:
        return notify_fail("��Ҫ�鿴ʲô������\n");
}

return 1;
}

