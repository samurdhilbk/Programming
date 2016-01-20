import Control.Applicative ((<$>))
import Control.Monad (forM_)
import Data.Set as S
import Debug.Trace
import Text.Printf

main = do
    t <- readLn :: IO Int
    forM_ [1..t] $ \i -> do
        [l, n, m, d] <- Prelude.map read <$> words <$> getLine :: IO [Int]
        ws <- Prelude.map read <$> words <$> getLine :: IO [Int]
        printf "Case #%d: %d\n" i $ solve l ws m d

solve :: Int -> [Int] -> Int -> Int -> Int
solve l ws m d =
    let washSet = Prelude.foldr S.insert S.empty
                  $ Prelude.map (\(a,id') -> (a,a,id')) $ zip ws [1..]
        drySet = Prelude.foldr S.insert S.empty $ zip (repeat 0) [1..m]
    in dryTime (washTimes l washSet []) drySet d

dryTime :: [Int] -> S.Set (Int, Int) -> Int -> Int
dryTime [] ds _ = fst $ S.findMax ds
dryTime (t:ts) ds d =
    let (tStart, id') = findMin ds
    in dryTime ts (insert (max t tStart + d, id') $ delete (tStart, id') ds) d

washTimes :: Int -> S.Set (Int, Int, Int) -> [Int] -> [Int]
washTimes 0 ws acc = reverse acc
washTimes loads ws acc =
    let (a,b,id') = S.findMin ws
    in washTimes (loads-1) (S.insert (a+b, b, id') $ S.delete (a, b, id') ws)
                 (a:acc)

traceShowId x = traceShow x x
