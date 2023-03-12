import java.util.*;

public class Main {
    static boolean isAlpha(char c) {
        return (c >= 97 && c <= 122);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String str = sc.next();
            int product = 1;
            for (int i = 0; i < str.length(); i++) {
                // int product=1;
                if (str.charAt(i) == '?') {
                    if (!(i == 0 || i == str.length() - 1)) {
                        if (str.charAt(i - 1) != str.charAt(i + 1))
                            product *= 24;
                        else
                            product *= 25;
                    }
                }

            }
            char c1 = str.charAt(0);
            char c2 = str.charAt(str.length() - 1);
            if ((c1 != c2) && isAlpha(c1) && isAlpha(c2) && product == 1)
                product = 0;

            System.out.println(product);
        }
    }
}
