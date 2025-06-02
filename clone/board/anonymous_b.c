// /clone/board/anonymous_b.c

inherit ITEM;
//inherit inherit/misc/bboard;

void create()
{
        seteuid(getuid());
        set_name("�������԰�",({"board"}));
        set("location", "/d/city/wumiao2");
        set("board_id", "anonymous_b");
        set("long", "����һ������Һ���ʦ�������������԰塣\n" );
        setup();
        set("capacity", 500);
}

string long()
{
        mapping *notes;
        int i, last_time_read;
        string msg, myid;

        notes = query("notes");
        msg = query("long");
        msg = msg + "���԰��ʹ�÷������ help board��\n";
        if (! pointerp(notes) || ! sizeof(notes)) return query("long");

        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
        myid = (string) this_player()->query("name") + "-" + this_player()->query("id");
        i = sizeof(notes) - 200;
        if (i < 0) i = 0;
        for (; i < sizeof(notes); i++)
        {
                if (notes[i]["author"] != myid)
                        continue;

                msg += sprintf("[%2d]  %-40s %s (%s)\n",
                        i + 1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15]);
        }
        return msg;
}

int do_discard(string arg)
{
        if (wiz_level(this_player()) < 1)
                return notify_fail("�㲻��ɾ�����������κ����ԡ�\n");

        return ::do_discard(arg);
}

int do_read(string arg)
{
        mapping *notes;
        int num;

        if (! arg || sscanf(arg, "%d", num) != 1)
                return notify_fail("ָ���ʽ��read <���Ա��>\n");
        notes = query("notes");
        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
                return notify_fail("û���������ԡ�\n");
        num--;

        if (wiz_level(this_player()) < 1 &&
            notes[num]["author"] != (string) this_player()->query("name") + "-" +
                                    this_player()->query("id"))
                return notify_fail("�㲻���Ķ���������в�������д�����ԡ�\n");

        return ::do_read(arg);
}

