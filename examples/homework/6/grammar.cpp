
/*
    Grammar
        S' -> S$

        S -> { El }

        El -> L
        El -> e

        L -> E , L
        L -> e

        E -> A
        E -> S

        A -> }
        A -> ,

        First(A) =                          '{', ','
        Follow(A) = Follow(E)

        First(E) = First(A) u First(S) =    '{', ',', '}'
        Follow(E) = First(L) u Follow(L) =  '{', ',', '}'

        First(S) =                          '{'
        Follow(S) = '$'

        First(L) = First(E) =               '{', ',', '}'
        Follow(L) = Follow(El) =            '}'
        
        First(El) = First(L) =              '{', ',', '}'
        Follow(El) = '}'

        First(S') = First(S) =              '{'
*/