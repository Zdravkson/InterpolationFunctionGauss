    double tmpcoef = coefficientMatrix[j][i] / coefficientMatrix[i][i];
            for(int k = 0; k < n; k++) {
                coefficientMatrix[j][k] -= (tmpcoef * coefficientMatrix[i][k]);
            }
        }