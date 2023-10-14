if(i == n - 1) {
            cout << ans[i];
        } else {
            cout << ans[i] << " * x^" << n - 1 - i << " + ";
        }