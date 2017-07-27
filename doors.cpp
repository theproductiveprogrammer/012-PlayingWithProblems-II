/**
 * Playing with Problems II
 */
/**
 * I think [href=/rotation.cpp.php](playing with problems)
 * is such an important concept
 * that I'm going to devote
 * another short blog post to
 * it.
 *
 * This time let's look at
 * another fun problem: opening
 * doors!
 */
/**
 * doors.png
 */
/**
 * *_There are n closed doors in a
 * long corridor, numbered 1 to
 * n. A person walks through and
 * opens each door. Another
 * person walks through and
 * closes every alternate door.
 * This continues with the i-th
 * person toggling the state of
 * every i-th door. How many
 * doors are left open after the
 * nth person is done?_*
 */
/**
 * (People have strange hobbies I
 * guess! :-D)
 *
 * The problem itself is easy
 * enough to understand. _*Let's
 * whip out our editors and dash
 * off a solution in no time!*_
 */
/**
 * but-wait.png
 */
/**
 * *___This [href=/rotation.cpp.php](is a terrible mistake)!___*
 */
/**
 * *__Rushing to a Solution__*
 *
 * If we rush to a solution we
 * will implement it something
 * like this:
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>

int doors_open(int n) {
    int doors[n];
    long num = 0;
    std::fill(doors, doors+n, 0);
    for(int i = 1;i <= n;i++) {
        int p = i;
        while (p <= n) {
            doors[p-1] = !doors[p-1];
            p += i;
            num++;
        }
    }
    return std::count(doors, doors+n, 1);
}

/**
 * Then we’ll spend time trying
 * to optimize it (let’s use a
 * bitset!) and use all the
 * technical wizardry and deep
 * knowledge we are so good at.
 * However, our solution will
 * remain O(nlog(n)) and become
 * harder and harder to maintain.
 */
/**
 * *__Playing with the Problem__*
 *
 * If, instead, we play around
 * with the problem for a bit
 * we will begin to notice a
 * pattern:
 *
 * Num Doors        Doors Open
 * 1                1
 * 2                1
 * 3                1
 * 4                1, 4
 * 5                1, 4
 * 6                1, 4
 * 7                1, 4
 * 8                1, 4
 * 9                1, 4, 9
 * 10               1, 4, 9
 *
 * Now we can clearly see a
 * pattern.
 */
/**
 * But why does this happen?
 * Well, stop here for a few
 * minutes, play with the
 * problem and I _*guarantee*_
 * you'll figure it out!
 *
 * And, once we understand it
 * the pattern, the solution
 * becomes so much simpler!
 */
/**
 * wow.png
 */
int doors_open(int n) {
    return std::sqrt(n); /* neat huh? */
}

/**
 * *__The Explanation__*
 *
 * If you’ve played with the
 * problem and still can’t
 * figure it out – I’ll explain
 * it for you. But before you
 * read ahead, do promise you’ve
 * tried it out yourself.
 *
 * Ok so if we think about it,
 * door 1 will be touched only
 * by person 1, door 2 will be
 * touched by person 1 and 2,
 * door 3 will be touched by
 * person 1 and 3, and so on. In
 * general door `i` will be
 * touched by _all the divisors
 * of `i`_.
 *
 *  Door 6               Door 9
 *     |                    |
 * 1  2  3  6            1  3  9
 * (touched by)       (touched by)
 *
 * Also if `a` touches a door
 * then
 *      b = i / a
 * also touches the same door!
 *
 * (If this seem complicated -
 * please play with the problem
 * and it'll all make sense!)
 *
 * So that means that for every
 * `a` that touches the door
 * there will be another `b`
 * that simply undo's whatever
 * `a` did!
 *
 * The only time this will not
 * happen is when b == a. In
 * other words - when
 *      i = a*a
 * which only happens for
 * perfect squares.
 *
 * If we want the count, all we
 * need to know is how many
 * perfect squares are
 * there in the line of doors
 * - which is sqrt(n)
 */
/**
 * As with my last post, I am
 * hoping to show you how
 * important (and fun) it can be
 * to play with the problems
 * given to you before trying to
 * find a solution. This is a
 * hard but excellent habit to
 * cultivate and will stand you
 * in good stead through your
 * career.
 */
int main(int argc, char* argv[]) {
    int num_doors_test[] = {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19,
        97, 128, 198, 234, 500,
        700, 1243, 4000
    };
    int len = sizeof(num_doors_test)/sizeof(num_doors_test[0]);
    for(int i = 0;i < len;i++) {
        int num_doors = num_doors_test[i];
        int num_open = doors_open_improved(num_doors);
        /* check */ assert(doors_open(num_doors) == num_open);
        std::cout << "For " << num_doors << " doors: "
                << num_open << " open\n";
    }
}

